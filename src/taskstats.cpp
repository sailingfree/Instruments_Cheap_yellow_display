#include <taskstats.h>

extern Stream *Console;

void getTaskStats(Stream & s) {
   static const int statsBufferSize = 1024;
    static char statsBuffer[statsBufferSize];

    static const int listBufferSize = 1024;
    static char listBuffer[listBufferSize];

    s.println("\n============ Task Stats ============");

    // Get runtime stats for CPU usage
    // This requires configGENERATE_RUN_TIME_STATS to be enabled
#if defined configGENERATE_RUN_TIME_STATS
    vTaskGetRunTimeStats(statsBuffer);
    s.println("Run Time Stats:");
    s.println(statsBuffer);

    // Get task list with state, priority, stack, and task number
    // Note: vTaskList output depends on configuration and may not include s.
    // affinities by default
    s.println("Task List:");
    s.printf("Blocked ('B'), Ready ('R'), Deleted ('D') or Suspended ('S')\n");
    s.println(F("**********************************"));
    s.println(F("Task          State   Prio    Stack    PID   Core")); 
    s.println(F("**********************************"));
    vTaskList(listBuffer);
    s.println(listBuffer);
    s.println(F("**********************************"));
#else
#warning task stats collection not enabled
#endif
    s.println("=====================================");
}

