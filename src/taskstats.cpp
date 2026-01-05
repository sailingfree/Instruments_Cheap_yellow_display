#include <taskstats.h>

extern Stream *Console;

int TaskLog(int argc, char ** argv) {
    static const int statsBufferSize = 1024;
    static char statsBuffer[statsBufferSize];

    static const int listBufferSize = 1024;
    static char listBuffer[listBufferSize];

    Console->println("\n============ Task Stats ============");

    // Get runtime stats for CPU usage
    // This requires configGENERATE_RUN_TIME_STATS to be enabled
#if defined configGENERATE_RUN_TIME_STATS
    vTaskGetRunTimeStats(statsBuffer);
    Console->println("Run Time Stats:");
    Console->println(statsBuffer);

    // Get task list with state, priority, stack, and task number
    // Note: vTaskList output depends on configuration and may not include core
    // affinities by default
    vTaskList(listBuffer);
    Console->println("Task List:");
    Console->println(listBuffer);
#else
#warning task stats collection not enabled
#endif
    Console->println("=====================================");
    return 0;
}
