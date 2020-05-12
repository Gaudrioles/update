#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib-2.0/glib.h>
#include <windows.h>

#define EXE_NAME "update.exe"

#define BUFFER 8192
#define TAILLE_MAX 1000

gchar* lecture_registre_wow64()
{
    gchar* registre_adresse = NULL;
    gchar* chaine;
    gsize longueur = 0;
    char tampon[TAILLE_MAX];
    DWORD buffer = BUFFER;

    registre_adresse = g_strdup("SOFTWARE\\WOW6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{5932EBAE-4CE4-4988-B71A-91459658AD84}_is1");

    if((RegGetValue(HKEY_LOCAL_MACHINE,registre_adresse,"UninstallString",RRF_RT_ANY, NULL, (PVOID)tampon, &buffer)) == 0)
    {
        g_free(registre_adresse);
        longueur = strlen(tampon) + 1;
        chaine = g_new(char, longueur);
        memcpy(chaine, tampon, longueur);

        return chaine;
    }

    g_free(registre_adresse);
    chaine = NULL;
    return chaine;
}

void lancement_programmme(char* executable, char* parametres, int hide)
{
    SHELLEXECUTEINFOA ShExecInfo = {0};
    ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
    ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
    ShExecInfo.hwnd = NULL;
    ShExecInfo.lpVerb = NULL;
    ShExecInfo.lpFile = executable;
    ShExecInfo.lpParameters = parametres;
    ShExecInfo.lpDirectory = NULL;
    ShExecInfo.nShow = hide;
    ShExecInfo.hInstApp = NULL;
    ShellExecuteExA(&ShExecInfo);
    WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
    CloseHandle(ShExecInfo.hProcess);

    return;
}

int main(void)
{
    gchar* tampon = NULL;

    tampon = g_strdup_printf("/F /IM \"%s\"", "novetat.exe");

    lancement_programmme("C:/WINDOWS/system32/taskkill.exe", tampon, SW_HIDE);

    g_free(tampon);

    printf("Mise en place du Warez");
    Sleep(1);
    printf(".");
    Sleep(1);
    printf(".");
    Sleep(1);
    printf(".");
    Sleep(1);
    printf(".");
    Sleep(1);
    printf(".");
    Sleep(1);
    printf(".");
    Sleep(1);
    printf(".\n");

    printf("Supression ancienne version\n");

    tampon = lecture_registre_wow64();

    if(tampon == NULL)
    {
        return EXIT_FAILURE;
    }

    lancement_programmme(tampon, "/SILENT", SW_SHOW);

    g_free(tampon);

    printf("Installation nouvelle version\n");

    lancement_programmme("C:/ProgramData/novetat/novetat.exe", NULL, SW_SHOW);

    return EXIT_SUCCESS;
}
