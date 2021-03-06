#ifndef FLEXIFUNCTION_SERVICES
#define FLEXIFUNCTION_SERVICES

#include "flexiFunctionTypes.h"
#include "../libUDB/events.h"
#include "../libUDB/libUDB_internal.h"
#include "flexifunction_options.h"

// References for sending acknowledge replies
extern uint16_t flexifunction_ref_result;
extern uint16_t flexifunction_ref_index;
extern uint16_t flexifunction_ref_command;

// State of the flexifunction services
extern uint16_t flexiFunctionState;

enum FLEXIFUNCTION_SERVICES_STATUS
{
	FLEXIFUNCTION_NOT_STARTED,
	FLEXIFUNCTION_INIT,					// Checking and loading nv memory
	FLEXIFUNCTION_WAITING,
	FLEXIFUNCTION_SEND_BUFFER_SPECIFIC,
	FLEXIFUNCTION_SEND_BUFFER_ALL,
	FLEXIFUNCTION_SENDING_BUFFER_ALL,
	FLEXIFUNCTION_SEND_STATISTICS,
	FLEXIFUNCTION_READ_NVMEMORY,		// Only read the memory
	FLEXIFUNCTION_READING_NVMEMORY,
	FLEXIFUNCTION_LOAD_NVMEMORY,		// Read NV memory and then commit it
	FLEXIFUNCTION_LOADING_NVMEMORY,
	FLEXIFUNCTION_COMMIT_RELOADED_BUFFER, // Request to commit buffer reloaded from memory
	FLEXIFUNCTION_WRITE_NVMEMORY,
	FLEXIFUNCTION_WRITING_NVMEMORY,
	FLEXIFUNCTION_INIT_NVMEMORY,		// Waiting for nv memory to initialise
	FLEXIFUNCTION_COMMIT_BUFFER,		// Request to commit buffer from mavlink
	FLEXIFUNCTION_COMMITTING_BUFFER,	// Checksum done and waiting for actual commit
	FLEXIFUNCTION_COMMIT_ACKNOWLEDGE,	// Commit done, send acknowledge
	FLEXIFUNCTION_COMMAND_ACKNOWLEDGE,
	FLEXIFUNCTION_BUFFER_FUNCTION_ACKNOWLEDGE,
//	FLEXIFUNCTION_SIZES_ACKNOWLEDGE,
	FLEXIFUNCTION_INPUT_DIRECTORY_ACKNOWLEDGE,
	FLEXIFUNCTION_OUTPUT_DIRECTORY_ACKNOWLEDGE,
};

enum FLEXIFUNCTION_COMMANDS
{
	FLEXIFUNCTION_COMMAND_COMMIT_BUFFER = 3,
	FLEXIFUNCTION_COMMAND_READ_NVMEMORY = 4,
	FLEXIFUNCTION_COMMAND_WRITE_NVMEMORY = 5,
	FLEXIFUNCTION_COMMAND_RELOAD_FROM_NVMEMORY = 6,
};


typedef struct tagNVMEM_FLEXIFUNCTION_DATA
{
	uint8_t			preamble[4];
	uint16_t			flexiFunctionsUsed;
	uint16_t 			checksum;
	FLEXIFUNCTION_DATASET	flexiFunction_dataset;
} NVMEM_FLEXIFUNCTION_DATA;

// Initialise the flexifunction low priority service
void flexiFunctionServiceInit(void);

// Trigger the flexifunction low priority service to run
void flexiFunctionServiceTrigger(void);

// Called by flexifunction loop to test for a new set of functions available
void flexiFunction_commit_buffer_check( void );

// Read running flexifunctions to the buffer with sizes
void flexiFunction_read_to_buffer(void);

// Read function settings from nv memory to buffer
void flexiFunction_read_nv_memory(void);

// Commit buffer to nv memory
void flexiFunction_write_nv_memory(void);

// Load function settings from nv memory, test checksum and then commit
void flexiFunction_load_nv_memory(void);

// Write a function to the buffer
void flexiFunction_write_buffer_function(uint8_t* pFuncData, uint16_t index, uint16_t address, uint16_t size, uint16_t count);

// Write a functions count to the buffer
//void flexiFunction_write_functions_count(uint16_t funcCount);

// Get functions count from buffer
uint16_t flexiFunction_get_functions_count( void );

// Write directory data
void flexiFunction_write_directory(uint8_t directory_type , uint8_t start_index, uint8_t count, uint8_t* pdirectory_data);


#endif 	//FLEXIFUNCTION_SERVICES

