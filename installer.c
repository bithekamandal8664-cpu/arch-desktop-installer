#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char selection[10];
    char KDE[1000];
    char gnome[1000];
    char systemd[1000];
    char shell[1000];
    char confirmation[1000];
    char niri[1000];
    char confirmation1[1000];

    printf("What desktop environment do you want?\n");
    printf("1. KDE-plasma\n");
    printf("2. GNOME\n");
    printf("3. hyprland (Note:- Window manager rather than a traditional DE)\n");
    printf("4. niri (Note:- Window manager rather than a traditional DE)\n");
    printf("choose the number:- ");

    fgets(selection, sizeof(selection), stdin);
    selection[strcspn(selection, "\n")] = '\0';

    if (strcmp(selection, "1") == 0) {
        snprintf(KDE, sizeof(KDE), "echo '1234' | sudo -S pacman -S --noconfirm plasma");
        system(KDE);
    } 
    else if (strcmp(selection, "2") == 0) {
        snprintf(gnome, sizeof(gnome), "echo '1234' | sudo -S pacman -S --noconfirm gnome");
        system(gnome);
    } 
    else if (strcmp(selection, "3") == 0) {
        printf("installing hyprland first...\n");
        snprintf(systemd, sizeof(systemd), "echo '1234' | sudo -S pacman -S --noconfirm hyprland");
        system(systemd);

        system(" git clone https://github.com/Prateek-squadron/hyprconf2lua.git &&"
               "cd hyprconf2lua &&"
               "./install.sh");
        system("~/.local/bin/hyprconf2lua ~/.config/hypr/hyprland.conf -o ~/.config/hypr/hyprland.lua");

        printf("\nNow which shell you want to use?\n");
        printf("1. Noctalia\n");
        printf("2. Caelestia\n");
        printf("choose one! :- ");

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        fgets(shell, sizeof(shell), stdin);
        shell[strcspn(shell, "\n")] = '\0';

        if (strcmp(shell, "1") == 0) {
            system("echo '1234' | sudo -S pacman -S --noconfirm noctalia");
            printf("Done installing noctalia\n");
        } 
        else if (strcmp(shell, "2") == 0) {
            system("yay -S --noconfirm --answerclean None --answerdiff None caelestia-shell");
            printf("done installing\n");
        }

        printf("Do you want to apply your selected shell? (yes/no):- ");
        fgets(confirmation, sizeof(confirmation), stdin);
        confirmation[strcspn(confirmation, "\n")] = '\0';

        if (strcmp(confirmation, "yes") == 0) {
            if (strcmp(shell, "1") == 0) {
                system("echo \"exec-once = qs -c noctalia-shell\" >> ~/.config/hypr/hyprland.conf");
            } else if (strcmp(shell, "2") == 0) {
                system("echo \"exec-once = caelestia shell\" >> ~/.config/hypr/hyprland.conf");
            }
            printf("added shell to your config!\n");
        } 
        else {
            return 0;
        }

        printf("starting hyprland now..\n");
        system("Hyprland");
    } 
    else if (strcmp(selection, "4") == 0) {
        snprintf(niri, sizeof(niri), "echo '1234' | sudo -S pacman -S --noconfirm niri");
        system(niri);

        printf("Which shell you want to use?:\n");
        printf("1. Noctalia\n");
        printf("2. Caelestia\n");

        fgets(confirmation1, sizeof(confirmation1), stdin);
        confirmation1[strcspn(confirmation1, "\n")] = '\0';


        if (strcmp(confirmation1, "1") == 0) {
            system("echo '1234' | sudo -S pacman -S --noconfirm noctalia");
            system("echo 'spawn-sh-at-startup \"qs -c noctalia-shell\"' >> ~/.config/niri/cfg/autostart.kdl");
            printf("added noctalia shell to autostartup!\n");
        } 
        else if (strcmp(confirmation1, "2") == 0) {
            system("yay -S --noconfirm --answerclean None --answerdiff None caelestia-shell");
            system("echo 'spawn-sh-at-startup \"caelestia shell\"' >> ~/.config/niri/cfg/autostart.kdl");
            printf("added caelestia shell to autostartup!\n");
        }
    }

    printf("\ninstalling additional packages including firefox, thunar, and kitty...\n");
    system("echo '1234' | sudo -S pacman -S --noconfirm firefox thunar kitty");

    printf("\nDone\n");
    return 0;
}
