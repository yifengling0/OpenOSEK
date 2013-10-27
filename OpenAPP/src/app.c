#include "Os.h"
#include "Com.h"
void StartupHook(void)
{
	Can_Init(NULL);
	StartNM(0);
	CanTp_Init();
}
extern void CanTp_Print(void);
TASK(TaskKeyMonitor)
{
	char chr;
	for(;;)
	{
		chr = (char)getchar();
		if('s' == chr)
		{
			GotoMode(0,NM_BusSleep);
			printf("Goto Bus Sleep.\n");
		}
		else if('w' == chr)
		{
			GotoMode(0,NM_Awake);
			printf("Goto Awake.\n");
		}
		else if('T' == chr)
		{
			TalkNM(0);
			printf("TalkNM(0).\n");
		}
		else if('S' == chr)
		{
			SilentNM(0);
			printf("SilentNM(0).\n");
		}
		else if('k' == chr)
		{
			StopNM(0);
			printf("StopNM\n");
		}
		else if('r' == chr)
		{
			StartNM(0);
			printf("StartNM\n");
		}
		else if('p' == chr)
		{
			// print the info of each module
			CanTp_Print();
		}
	}
	TerminateTask();
}

