#ifndef DEBUGMEM_H
#define DEBUGMEM_H
#include"memorymanager.h"
/*
Basic dynamic memory tracer: works by replacing new/delete, new[]/delete[] with
        overloaded versions that track the addresses of the allocated memory.

Usage:    All three files: debugmem.h, memorymanager.cpp/.h must be present in project.
        Include debugmem.h in all files that calls new and delete, do not
        explicity include memorymanager.h.  memorymanager.cpp/.h only need to be present
        in the project, you do not need to do anything or call any function within them.
        Everything is handled with the inclusion of debugmem.h.

        Replace all calls to 'new' you want to track with DEBUG_NEW

        To get a report of the current allocations call GETMEMORYREPORT().
*/

// Check for current allocations
#define GETMEMORYREPORT() memoryReport()

// Reset the number of tracked allocations, does not deallocate
#define RESET() reset()

// Get the number of tracked allocations
#define SIZE() getNumAlloc()

#define DEBUG_NEW new(__FILE__, __func__, __LINE__)

#endif
