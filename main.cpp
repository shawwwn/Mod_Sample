#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

	CHAR lpFinalCmdLine[512];
	ZeroMemory(&lpFinalCmdLine, 512);

	// TODO: Edit the parameters, make sure these is a space at the end of the string. 
	LPSTR lpCustomCmdLine = "-mpq YourMpqName.mpq -race Human,Orc,Undead,NightElf,Naga,IceTroll,BloodElf ";

	strcpy(lpFinalCmdLine, "Nirvana.exe ");
	strcat(lpFinalCmdLine, lpCustomCmdLine);
	strcat(lpFinalCmdLine, lpCmdLine);

 	// Start the process
    if(!CreateProcess("Nirvana.exe", lpFinalCmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) 
    {
        MessageBox(NULL, "Failed to launch Nirvana.exe! \nPlease check if this application is in the same directory as Nirvana.", "Error", MB_OK);
        return ERROR_FILE_NOT_FOUND;
    }

	return ERROR_SUCCESS;
}
