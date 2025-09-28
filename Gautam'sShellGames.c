/* Please note: This code has been written and tested in a Linux environment. 
 As such, it may not function as expected or may encounter compatibility issues when run on a Windows operating system.
 Differences in system calls, file handling, or available libraries between Linux and Windows could lead to unexpected behavior.
 It is recommended to adapt and test the code accordingly if it is intended to be executed in a Windows environment.
*/

// Necessary Header Files
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<ctype.h>
#include<string.h>

// Font and Color for Texts
#define B "\033[1m"
#define I "\033[3m"
#define U "\033[4m"
#define R "\033[31m"
#define G "\033[32m"
#define Y "\033[33m"
#define b "\033[34m"
#define M "\033[35m"
#define C "\033[36m"
#define W "\033[37m"
#define r "\033[0m"

// Text Animations
void prtext(const char *text){      
    while(*text){
        putchar(*text++);
        fflush(stdout);
        usleep(100000);
    }
}

// For Loading Percentage And Dot Effects
void loadScreen(int length){
    int percentage;
    for(int i=0;i<=length;i++){
        percentage=i*100/length;
        printf(W B I"\033[s"); // Save cursor position
        for(int j=0;j<=length;j++){
            if(j<i)
            printf(".");
            else
            printf(" ");
        }
        printf("%5d%%\033[u",percentage); // Restore cursor position & print the percentage at 10 width
        printf(""r);
        fflush(stdout);
        usleep(100000);
    }
    printf("\n");
}

// Only Percentage Effects
void loadPercentage(int length){
    for(int i=0;i<=length;i++){
        int percentage = i*100/length;
        printf(W B I"\033[s %5d%%\033[u",percentage);
        fflush(stdout);
        usleep(100000);
    }
    puts(" ");
}

// Fake Connection Request
void connectionRequest(){
    system("clear");
    prtext(B I"Establishing A Secure Server Connection");
    loadScreen(15);
    printf(B I"Requesting for Handshake");
    loadScreen(10);
    printf(R B I"Handshake : FAILED\n");
    printf(W B I"Retrying The Handshake Protocol");
    loadScreen(10);
    printf(G B I"Handshake : SUCCESSFUL\n");
    printf(W B I"Connected To A Secure Network\n");
    prtext(B I"Connection Established Successfully\n");
    sleep(2);
    system("clear");
    prtext(B I"Checking Your System Hardware Requirement");
    loadScreen(12);
    printf(B I G "All Clear !!! Meet All The Specification\n" W);
    prtext("Initialing The Game");
    loadPercentage(15);
    prtext(M B I"You Are About To Enter The Gautam's Shell Games!!! Embraced Yourself"r);
    sleep(2);
    system("clear");
}

// Fake Disconnect Request
void disconnectRequest(){
    prtext(B I"Terminating Secure Server Connection");
    loadScreen(10);
    prtext(B I"Sending Termination Signal");
    loadScreen(5);
    printf(G B I"Handshake Terminated\n"r);
    prtext(B I"Disconnecting Network...");
    loadScreen(12);
    printf(G B I"Disconnected Successfully\n");
    puts("Secure Session Closed"r);
    sleep(1);
}

// Intro For Main Menu
void intro(){
     printf(B I "|===============================================================|\n");
    printf("|                                                               |\n");
    printf(B I C "|     ");
    prtext("\033[4mWelcome to Gautam's Shell Game! Let the Fun Begin!!!\033[0m");
    printf(W B C "      |\n" r);
    printf(B I "|                                                               |\n");
    printf("|===============================================================|\n");
    sleep(1);
    printf("|                                                               |\n");
    printf(G "|     1. Rock 🪨 | Paper 📄 | Scissors ✂️ — The Classic Showdown.  |\n");
    printf("|     2. Guess the Number 🧠  — Test Your Luck and Smarts.       |\n");
    printf("|     3. Snake 🐍 | Water 💧 | Gun 🔫  — Choose Your Fighter.      |\n");
    printf("|     4. Head 🪖 | Tail 🐾 — Choose Your Side.                    |\n");
    printf("|     5. Memorize 🧠 | Type ⌨️ — Test Your Memory!                |\n");
    printf("|                                                               |\n" r);
    printf(B I "|===============================================================|\n");
    printf(Y "|    Press 'Q' to Retreat - Live to Fight Another Day!!!        |\n" r);
    printf(B I "|===============================================================|\n\n" r);

}

// Function Body For Rock Paper And Scissor Game
void rockPaperScissor(){
    char word[100],aiChoice,skip;
    int aiNumber, yourScore=0, aiScore=0;
    system("clear");
    prtext("\033[1;3;4;31m\t\t\tInstructions\n\033[0m\n");
    printf(W B I "|===============================================================|\n");
    printf("|                    Get Ready, Soldier!                        |\n");
    printf("|          You're on a mission: Rock, Paper, Scissors           |\n");
    printf("|===============================================================|\n");
    printf("|                                                               |\n");
    printf(R B I "| Follow the instructions carefully:                            |\n");
    printf(C B I "|   -> You get 3 chances to win against the AI.                 |\n");
    printf("|   -> Choose your weapon wisely:                               |\n");
    printf("|      * R for Rock                                             |\n");
    printf("|      * P for Paper                                            |\n");
    printf("|      * S for Scissors                                         |\n");
    printf("|                                                               |\n");
    printf(G B I "| Scoring Rules:                                                |\n");
    printf("|   -> You score 1 point if you win the round.                  |\n");
    printf("|   -> In case of a draw, both you and the AI get 1 point.      |\n");
    printf("|   -> No points for a loss.                                    |\n");
    printf("|                                                               |\n");
    printf(Y B I "| Notes:                                                        |\n");
    printf("|   -> Give your best shot against the AI.                      |\n");
    printf("|   -> All the best, Soldier!                                   |\n");
    printf("|                                                               |\n");
    printf(R B I "| Quit Option:                                                  |\n");
    printf("|   -> Press 'Q' or 'q' at any time to exit the game.           |\n");
    printf("|                                                               |\n");
    printf(W B I "|===============================================================|\n");
    printf(M B I "|                Your mission begins now. Good luck!            |\n");
    printf(W B I "|===============================================================|\n\n");
    printf(B I W "Press 'Enter' if you have read all the Instructions..." r);
    char buffer[50];
    fgets(buffer, sizeof(buffer), stdin);

    
    for (int i=1;i<=3;i++){
        aiNumber=rand()%100+1;
        if (aiNumber<34) aiChoice='r';
        else if (aiNumber<67) aiChoice='p';
        else aiChoice='s';
        system("clear");
        printf(C B I"================================================================\n");
        printf("                        ⚔️  MISSION START  ⚔️                     \n");
        printf("================================================================\n");
        printf("\n");
        printf("                The AI is locked and loaded...\n");
        printf("              It's going to crush you if you slip!\n");
        printf("\n");
        printf("              🎮  Let the game begin, Soldier!  🎮\n");
        printf("                 May your choices be wise...\n\n");
        printf(b B I"================================================================\n");
        printf("                        🔁  ROUND %d BEGINS  🔁             \n", i);
        printf("================================================================\n\n");
        printf(W B I">> Enter your move (R = Rock, P = Paper, S = Scissors): "r);
        fgets(word,sizeof(word),stdin);
        word[strcspn(word,"\n")]='\0';
        word[0]=tolower(word[0]);
        if(word[0]=='q'||word[0]=='Q'){
            system("clear");
            prtext(B I W "🤖 AI: Hahaha! Did I scare you already, human? Run while you can!\n");
            printf(M B I "🪖 Commander: Stand tall, soldier! We don’t quit like losers!!!\n" r);
            sleep(2);
            system("clear");
            break;
        }
        system("clear");
        if(strlen(word)==1){
            if(word[0]=='r'||word[0]=='p'||word[0]=='s'){
                if(word[0]==aiChoice){
                    printf(W B I"\n***************************************\n");
                    printf("⚖️  ROUND OVER: IT'S A DRAW! ⚖️\n");
                    printf("***************************************\n");
                    printf("   You played: %c\n", word[0]);
                    printf("   AI played: %c\n", aiChoice);
                    printf("\n>> Both sides stand strong! <<\n");
                    printf(">> No winner this time. Brace yourself for the next round! <<\n");
                    printf("***************************************\n\n"r);
                    yourScore++;
                    aiScore++;
                    sleep(3);
                    system("clear");
                }
                else if ((word[0]=='r'&&aiChoice=='p')||(word[0]=='p'&&aiChoice=='s')||(word[0]=='s'&&aiChoice=='r')){
                    printf(R B I"\n***************************************\n");
                    printf("🔥  ROUND OVER: AI TAKES THE VICTORY! 🔥\n");
                    printf("***************************************\n");
                    printf("   You played: %c\n", word[0]);
                    printf("   AI played: %c\n", aiChoice);
                    printf("\n>> AI lands a critical hit! <<\n");
                    printf(">> Don't give up, Soldier! Ready for the next round? <<\n");
                    printf("***************************************\n\n"r);
                    aiScore++;
                    sleep(3);
                    system("clear");
                }
                else {
                    printf(G B I"\n***************************************\n");
                    printf("🏆  ROUND OVER: YOU WIN THIS ROUND! 🏆\n");
                    printf("***************************************\n");
                    printf("   You played: %c\n", word[0]);
                    printf("   AI played: %c\n", aiChoice);
                    printf("\n>> Victory is yours, Soldier! <<\n");
                    printf(">> Keep the momentum going for the next round! <<\n");
                    printf("***************************************\n\n"r);
                    yourScore++;
                    sleep(3);
                    system("clear");
                }
            }
            else {
                printf(b B I"\n***************************************\n");
                printf("⚠️  INVALID MOVE ENTERED! ⚠️\n");
                printf("***************************************\n");
                printf(">> That’s not a valid choice, Soldier! <<\n");
                printf(">> Use only R, P, or S. Try again! <<\n");
                printf("***************************************\n\n"r);
                sleep(2);
                system("clear");
                i--;
                continue;
                }
        }
        else {
            printf(M B I"\n***************************************\n");
            printf("⚠️  INVALID MOVE ENTERED! ⚠️\n");
            printf("***************************************\n");
            printf(">> That’s not a valid choice, Soldier! <<\n");
            printf(">> Use only R, P, or S. Try again! <<\n");
            printf("***************************************\n\n"r);
            sleep(2);
            system("clear");
            i--;
            continue;
        }
    }
    if(yourScore>aiScore){
        printf(G B I"\n***************************************\n");
        printf("🏆  MISSION ACCOMPLISHED! YOU WIN! 🏆\n");
        printf("***************************************\n");
        printf("   Final Score:\n");
        printf("   You played: %d\n", yourScore);
        printf("   AI played: %d\n", aiScore);
        printf(">> Outstanding performance, Soldier! <<\n");
        printf(">> Mission complete. Ready for the next challenge? <<\n");
        printf("***************************************\n\n"r);
        printf(W B I"Press Enter To Skip....."r);
        getchar();
        system("clear");
    }
    else if(yourScore<aiScore){
        printf(R B I"\n***************************************\n");
        printf("💀  MISSION FAILED! AI WINS THE GAME! 💀\n");
        printf("***************************************\n");
        printf("   Final Score:\n");
        printf("   You played: %d\n", yourScore);
        printf("   AI played: %d\n", aiScore);
        printf(">> The AI crushed your mission, Soldier! <<\n");
        printf(">> Don't lose hope — regroup and try again! <<\n");
        printf("***************************************\n\n"r);
        printf(W B I"Press Enter To Skip....."r);
        getchar();
        system("clear");
    }
    else{
        printf(W B I"\n***************************************\n");
        printf("⚔️  MISSION ENDS IN A TIE! ⚔️\n");
        printf("***************************************\n");
        printf("   Final Score:\n");
        printf("   You played: %d\n", yourScore);
        printf("   AI played: %d\n", aiScore);
        printf(">> Neither side gained the upper hand this time. <<\n");
        printf(">> The battle continues... Prepare for the next mission! <<\n");
        printf("***************************************\n\n"r);
        printf(W B I"Press Enter To Skip....."r);
        getchar();
        system("clear");
    }
}

//Function For Guess the Number Game

void guessTheNumber(){
    int randomNumber,attempt=1;
    system("clear");
    prtext("\t\033[1;3;4;31m\t\t\tInstructions\n\033[0m\n");
    printf(W B I"|*************************************************************************************|\n");
    printf("|                              ");
    printf("\033[4mWelcome to 'Guess The Number'\033[0m");
    printf(W B I"                          |\n");
    printf("|                                                                                     |\n");
    printf(C "|   Objective:                                                                        |\n");
    printf("|     - Guess the secret number chosen by the AI.                                     |\n");
    printf("|     - You have a maximum of 10 attempts.                                            |\n");
    printf("|                                                                                     |\n");
    printf(Y"|   Game Rules:                                                                       |\n");
    printf("|     - The number is randomly selected between 1 and 100.                            |\n");
    printf("|     - After each guess, a hint will be provided:                                    |\n");
    printf("|          → 'Too High' — if your guess is above the target number.                   |\n");
    printf("|          → 'Too Low'  — if your guess is below the target number.                   |\n");
    printf("|                                                                                     |\n");
    printf(G"|   Tips:                                                                             |\n");
    printf("|     - Use the hints to narrow down your next guess.                                 |\n");
    printf("|     - Think logically and plan each move — you only have 10 chances.                |\n");
    printf("|                                                                                     |\n");
    printf(R B I"|   Quit Option:                                                                      |\n");
    printf("|     - If you wish to quit the game at any time, press 'Q' or 'q' to exit.           |\n"r);
    printf("|                                                                                     |\n");
    printf(M B I"|                        Your mission begins now. Good luck!                          |\n"r);
    printf(W B I"|*************************************************************************************|\n\n"r);
    printf(B I "Press 'Enter' if you have read all the Instructions "r);
    char buffer[50];
    fgets(buffer, sizeof(buffer), stdin);
    system("clear");
    printf(C B I"|---------------------------------------------------------------------------------|\n");
    printf("|                         The AI Has Selected a Secret Number                     |\n");
    printf("|       Let’s see how many attempts it takes you to guess it correctly...         |\n");
    printf("|---------------------------------------------------------------------------------|\n\n"r);

    randomNumber=rand()%100+1;
    do{
        int valid =1, inc=0,guessNumber=0;
        char guess[100],skip[100];
        printf(b B I"Attempt %d ",attempt);
        printf(Y B I"Guess The Number : "r);
        scanf("%s",guess);
        if(guess[0]=='Q'||guess[0]=='q'){
            system("clear");
            prtext(B I W "🤖 AI: Hahaha! Did I scare you already, human? Run while you can!\n");
            printf(M B I "🪖 Commander: Stand tall, soldier! We don’t quit like losers!!!\n" r);
            sleep(2);
            system("clear");
            break;
        }
        while(guess[inc]!='\0'){
            if(!isdigit(guess[inc])){
                valid=0;
                break;
            }
            guessNumber=guessNumber*10+(guess[inc]-'0');
            inc++;
        }
        if(!valid){
            printf("\033[1;31m Soldier, That’s Not Even a Number! What Are You Doing? Stop Making Numbers Cry!\n"r);
            sleep(2);
            continue;
        }
        
        if(guessNumber<1 || guessNumber>100){
            printf(Y B I"Are You Sure You Read The Instructions, Or Did You Just Wink At Them?\n"r);
            continue;
        }
        
        // scanf("%d",&guess);
        // getchar();
        // printf("%d\n",randomNumber);
        
        
        // fgets(input,sizeof(input),stdin);   // Get the User Input as a String
        // if(sscanf(input,"%d",&guess)!=1){   // Conversion of string to Integer
        //     puts("Whoa, that’s not a number, Einstein! Let’s try using digits this time, okay?");
        //     attempt++;
        //     continue;
        // }
        // if(strchr(input,'.')!=NULL){
        //     printf("Floats got no clearance here. Integer only zone!\n");
        //     attempt++;
        //     continue;
        // }
        if(randomNumber==guessNumber){
            system("clear");
            getchar();
            printf(G B I"\n\n\n");
            printf("\t\t|---------------------------------------------------------------------|\n");
            printf("\t\t|           Mission Accomplished — You've Cracked the Code!           |\n");
            printf("\t\t|                                                                     |\n");
            printf("\t\t|           Hurray! You guessed the number in %d attempt(s).           |\n", attempt);
            printf("\t\t|          Your skill and determination have saved the Earth.         |\n");
            printf("\t\t|        Mission success, soldier. Earth is safe under your watch!    |\n");
            printf("\t\t|---------------------------------------------------------------------|\n\n"r);
            printf(W B I"\nPress Enter To Skip....."r);
            // sleep(5);
            break;
        }
        else if (guessNumber>randomNumber){
            printf(W B I"Soldier, your guess is too high. Adjust your target and try a lower number.\n");
            if (guessNumber - randomNumber <= 5) {
                printf(M B I"Excellent work, soldier! You’re extremely close to the correct number.\n"r);
            }
            attempt++;
        }
        else if (guessNumber<randomNumber) {
            printf(W B I"Soldier, your guess is too low. Try a slightly higher number.\n");
            if (randomNumber - guessNumber <= 5) {
                printf(M B I"Excellent work, soldier! You’re very close to the correct number.\n"r);
            }
            attempt++;
        }
        else {
            system("clear");
            prtext(Y B I"\nAre You Serious Soldier Press a Damn Number You Fool\n\n"r);
            attempt++;
        }
        if (attempt==11){
            system("clear");
            getchar();
            printf(R B I"\n\n\n");
            printf("\t\t|------------------------------------------------------------|\n");
            printf("\t\t|               Mission Failed — Earth Has Fallen            |\n");
            printf("\t\t|                                                            |\n");
            printf("\t\t|             The mission was not accomplished in time.      |\n");
            printf("\t\t|              Perhaps another soldier could succeed.        |\n");
            printf("\t\t|------------------------------------------------------------|\n"r);
            // sleep(5);
            printf(W B I"\nPress Enter To Skip....."r);
            break;
        }
        
    }while(1);
    getchar();
}


// Function For Snake Water Gun Game

void snakeWaterGun(){
    char word[100],aiChoice;
    int aiNumber, yourScore=0, aiScore=0;
    system("clear");
    prtext("\033[1;3;4;31m\t\t\tInstructions\n\033[0m\n");
    printf(W B I "|===============================================================|\n");
    printf("|                    Get Ready, Soldier!                        |\n");
    printf("|           You're on a mission: Snake, Water, Gun              |\n");
    printf("|===============================================================|\n");
    printf("|                                                               |\n");
    printf(R B I "| Follow the instructions carefully:                            |\n");
    printf(C B I "|   -> You get 3 chances to win against the AI.                 |\n");
    printf("|   -> Choose your weapon wisely:                               |\n");
    printf("|      * S for Snake                                            |\n");
    printf("|      * W for Water                                            |\n");
    printf("|      * G for Gun                                              |\n");
    printf("|                                                               |\n");
    printf(G B I "| Scoring Rules:                                                |\n");
    printf("|   -> You score 1 point if you win the round.                  |\n");
    printf("|   -> In case of a draw, both you and the AI get 1 point.      |\n");
    printf("|   -> No points for a loss.                                    |\n");
    printf("|                                                               |\n");
    printf(Y B I "| Notes:                                                        |\n");
    printf("|   -> Give your best shot against the AI.                      |\n");
    printf("|   -> All the best, Soldier!                                   |\n");
    printf("|                                                               |\n");
    printf(R B I "| Quit Option:                                                  |\n");
    printf("|   -> Press 'Q' or 'q' at any time to exit the game.           |\n");
    printf("|                                                               |\n");
    printf(W B I "|===============================================================|\n");
    printf(M B I "|                Your mission begins now. Good luck!            |\n");
    printf(W B I "|===============================================================|\n\n");
    printf(B I W "Press 'Enter' if you have read all the Instructions..." r);
    char buffer[50];
    fgets(buffer, sizeof(buffer), stdin);
    
    for (int i=1;i<=3;i++){
        aiNumber=rand()%100+1;
        if (aiNumber<34) aiChoice='s';
        else if (aiNumber<67) aiChoice='w';
        else aiChoice='g';
        system("clear");
        printf(C B I"================================================================\n");
        printf("                        ⚔️  MISSION START  ⚔️                     \n");
        printf("================================================================\n");
        printf("\n");
        printf("                The AI is locked and loaded...\n");
        printf("              It's going to crush you if you slip!\n");
        printf("\n");
        printf("              🎮  Let the game begin, Soldier!  🎮\n");
        printf("                 May your choices be wise...\n\n");
        printf(B b I"================================================================\n");
        printf("                        🔁  ROUND %d BEGINS  🔁             \n", i);
        printf("================================================================\n\n"r);
        printf(W B I">> Enter your move (S = Snake, W = Water, G = Gun): "r);
        fgets(word,sizeof(word),stdin);
        system("clear");
        word[strcspn(word,"\n")]='\0';
        word[0]=tolower(word[0]);
        if(word[0]=='q'||word[0]=='Q'){
            prtext(B I W "🤖 AI: Hahaha! Did I scare you already, human? Run while you can!\n");
            printf(M B I "🪖 Commander: Stand tall, soldier! We don’t quit like losers!!!\n" r);
            sleep(2);
            system("clear");
            break;
        }
        if(strlen(word)==1){
            if(word[0]=='s'||word[0]=='w'||word[0]=='g'){
                if(word[0]==aiChoice){
                    printf(W B I"\n***************************************\n");
                    printf("⚖️  ROUND OVER: IT'S A DRAW! ⚖️\n");
                    printf("***************************************\n");
                    printf("   You played: %c\n", word[0]);
                    printf("   AI played: %c\n", aiChoice);
                    printf("\n>> Both sides stand strong! <<\n");
                    printf(">> No winner this time. Brace yourself for the next round! <<\n");
                    printf("***************************************\n\n"r);
                    yourScore++;
                    aiScore++;
                    sleep(3);
                    system("clear");
                }
                else if ((word[0]=='s'&&aiChoice=='g')||(word[0]=='w'&&aiChoice=='s')||(word[0]=='g'&&aiChoice=='w')){
                    printf(R B I"\n***************************************\n");
                    printf("🔥  ROUND OVER: AI TAKES THE VICTORY! 🔥\n");
                    printf("***************************************\n");
                    printf("   You played: %c\n", word[0]);
                    printf("   AI played: %c\n", aiChoice);
                    printf("\n>> AI lands a critical hit! <<\n");
                    printf(">> Don't give up, Soldier! Ready for the next round? <<\n");
                    printf("***************************************\n\n"r);
                    aiScore++;
                    sleep(3);
                    system("clear");
                }
                else{
                    printf(G B I"\n***************************************\n");
                    printf("🏆  ROUND OVER: YOU WIN THIS ROUND! 🏆\n");
                    printf("***************************************\n");
                    printf("   You played: %c\n", word[0]);
                    printf("   AI played: %c\n", aiChoice);
                    printf("\n>> Victory is yours, Soldier! <<\n");
                    printf(">> Keep the momentum going for the next round! <<\n");
                    printf("***************************************\n\n"r);
                    yourScore++;
                    sleep(3);
                    system("clear");
                    continue;
                }
            }
            else{
                printf(b B I"\n***************************************\n");
                printf("⚠️  INVALID MOVE ENTERED! ⚠️\n");
                printf("***************************************\n");
                printf(">> That’s not a valid choice, Soldier! <<\n");
                printf(">> Use only S, W, or G. Try again! <<\n");
                printf("***************************************\n\n"r);
                sleep(2);
                i--;
                system("clear");
                }
        }
        else{
            printf(M B I"\n***************************************\n");
            printf("⚠️  INVALID MOVE ENTERED! ⚠️\n");
            printf("***************************************\n");
            printf(">> That’s not a valid choice, Soldier! <<\n");
            printf(">> Use only S, W, or G. Try again! <<\n");
            printf("***************************************\n\n"r);
            sleep(2);
            system("clear");
            i--;
            continue;
        }
    }
    if(yourScore>aiScore){
        printf(G B I"\n***************************************\n");
        printf("🏆  MISSION ACCOMPLISHED! YOU WIN! 🏆\n");
        printf("***************************************\n");
        printf("   Final Score:\n");
        printf("   You played: %d\n", yourScore);
        printf("   AI played: %d\n", aiScore);
        printf(">> Outstanding performance, Soldier! <<\n");
        printf(">> Mission complete. Ready for the next challenge? <<\n");
        printf("***************************************\n\n"r);
        printf(W B I"Press Enter To Skip....."r);
        getchar();
        system("clear");
    }
    else if(yourScore<aiScore){
        printf(R B I"\n***************************************\n");
        printf("💀  MISSION FAILED! AI WINS THE GAME! 💀\n");
        printf("***************************************\n");
        printf("   Final Score:\n");
        printf("   You played: %d\n", yourScore);
        printf("   AI played: %d\n", aiScore);
        printf(">> The AI crushed your mission, Soldier! <<\n");
        printf(">> Don't lose hope — regroup and try again! <<\n");
        printf("***************************************\n\n"r);
        printf(W B I"Press Enter To Skip....."r);
        getchar();
        system("clear");
    }
    else{
        printf(W B I"\n***************************************\n");
        printf("⚔️  MISSION ENDS IN A TIE! ⚔️\n");
        printf("***************************************\n");
        printf("   Final Score:\n");
        printf("   You played: %d\n", yourScore);
        printf("   AI played: %d\n", aiScore);
        printf(">> Neither side gained the upper hand this time. <<\n");
        printf(">> The battle continues... Prepare for the next mission! <<\n");
        printf("***************************************\n\n"r);
        printf(W B I"Press Enter To Skip....."r);
        getchar();
        system("clear");
    }
}

//  Function For Head or Tail Game
void headTail(){
    char choice[100],skip[10];
    int score=0;
    system("clear");
    prtext("\033[1;3;4;31m\t\t\tInstructions\n\033[0m\n");
    printf(W B I "|===============================================================|\n");
    printf("|                    Get Ready, Soldier!                        |\n");
    printf("|                 Welcome to the Head & Tail Game               |\n");
    printf("|===============================================================|\n");
    printf("|                                                               |\n");
    printf(R B I "| Mission Brief:                                                |\n");
    printf(C B I "|   -> It's a quick reflex game of luck and choice.             |\n");
    printf("|   -> Try to guess what the AI will choose: Head or Tail.      |\n");
    printf("|                                                               |\n");
    printf(G B I "| Game-Play Instructions:                                        |\n");
    printf("|   -> You have 3 rounds to challenge the AI.                   |\n");
    printf("|   -> For each round, choose:                                  |\n");
    printf("|      * H for Head                                             |\n");
    printf("|      * T for Tail                                             |\n");
    printf("|                                                               |\n");
    printf(Y B I "| Scoring Rules:                                                |\n");
    printf("|   -> You get 1 point for every correct guess.                 |\n");
    printf("|   -> No points for wrong guesses.                             |\n");
    printf("|                                                               |\n");
    printf(R B I "| Quit Option:                                                  |\n");
    printf("|   -> Press 'Q' or 'q' at any time to exit the game.           |\n");
    printf("|                                                               |\n");
    printf(W B I "|===============================================================|\n");
    printf(M B I "|              Your mission begins now. Good luck!              |\n");
    printf(W B I "|===============================================================|\n\n");
    printf(B I W "Press Enter To 'Skip', If You Have Read The Instructions  " r);
    fgets(skip,sizeof(skip),stdin);
    for(int i=0;i<3;i++){
        int num=rand()%2;
        system("clear");
        // printf("%d\n",num);
        printf(C B I"=======================================================\n");
        puts("🪖 Commander: “Guess right or get schooled, rookie!");
        puts("🤖 AI: “Your luck's trash. I’m winning.”");
        puts("🪖 Commander: “Game on. Let's see you try!”");
        printf("=======================================================\n\n"r);
        printf(b B I"\t\t \033[4mRound %d\033[0m\n\n",i+1);
        printf(B W I"Press H and T for Head and Tail Respectfully : "M);
        fgets(choice,sizeof(choice),stdin);
        choice[strcspn(choice,"\n")]='\0';
        choice[0]=toupper(choice[0]);
        if(choice[0]=='Q'||choice[0]=='q'){
            system("clear");
            prtext(r B I W "🤖 AI: Hahaha! Did I scare you already, human? Run while you can!\n");
            printf(M B I "🪖 Commander: Stand tall, soldier! We don’t quit like losers!!!\n" r);
            sleep(2);
            puts("clear");
            break;
        }
        if(strlen(choice)==1 && (choice[0]=='H'||choice[0]=='T')){
            char* result=(num==1)?"H":"T";
            if(strcmp(result,choice)==0){
                printf(G B I"\nYou Guess It Right, AI Has Chosen %s\n",result);
                puts("Great, You Score +1 Points! \n"r);
                score++;
            }
            else { 
                printf(R B I"\nYou Guess it Wrong, It Was %s\n",result);
                puts("Too Bad, You Score No Points! "r);
            }
        }   
        else{
            puts(M B I"Invalid Key Is Pressed!!!\n"r);
            i--;
        }
        sleep(2);
    }
    system("clear");
    puts(G B I"=======================================================");
    printf("          Out of 3 Round You Score : %d               \n",score);
    puts("======================================================="r);
    if(score==3){
        prtext(C B I"🤖 AI: 🎉  Perfect Game!!! You Are A Phenomenal Mind Reader\n\n"r);
        printf(W B I"Press Enter To Skip....."r);
        getchar();
        system("clear");
    }
    else if(score>=1){
        puts(b B I"🤖 AI: 👍  Fair Game-Play, You Did Your Best!!!\n\n"r);
        printf(W B I"Press Enter To Skip....."r);
        getchar();
        system("clear");
    }
    else{
        puts(R B I"🤖 AI: 😅  Better Luck Next Time !!!\n\n"r);
        printf(W B I"Press Enter To Skip....."r);
        getchar();
        system("clear");
        
    }
    
}

// Function For Memory Test Game
int memoryTest(){
    int score=0,timetaken=0;
    system("clear");
    prtext("\033[1;3;4;31m\t\t\tInstructions\n\033[0m\n");
    printf(W B I "|===============================================================|\n");
    printf("|                  Memory Test Challenge!                       |\n");
    printf("|            You have 5 rounds to beat the AI!                  |\n");
    printf("|          Test your observation and memory skills!             |\n");
    printf("|===============================================================|\n");
    printf("|                                                               |\n");
    printf(R B I "| Follow the instructions carefully:                            |\n");
    printf(C B I "|   -> A word will be shown briefly on the screen.              |\n");
    printf("|   -> You have only 2 seconds to memorize the word.            |\n");
    printf("|   -> After the word disappears, type the exact word.          |\n");
    printf("|                                                               |\n");
    printf(Y B I "| Notes:                                                        |\n");
    printf("|   -> Pay close attention to spelling, uppercase, lowercase,   |\n");
    printf("|      and special characters.                                  |\n");
    printf("|   -> You have 5 chances (rounds). Try to win more rounds      |\n");
    printf("|      than the AI.                                             |\n");
    printf("|   -> Try to remember as accurately and quickly as possible.   |\n");
    printf("|                                                               |\n");
    printf(R B I "| Quit Option:                                                  |\n");
    printf("|   -> Press 'Q' or 'q' at any time to exit the game.           |\n");
    printf("|                                                               |\n");
    printf(W B I "|===============================================================|\n");
    printf(M B I "|              Your mission begins now. Good luck!              |\n");
    printf(W B I "|===============================================================|\n\n");
    printf(B I W "Press 'Enter' if you have read all the Instructions " r);
    // fgets(enter,sizeof(enter),stdin);
    // enter[strcspn(enter,"\n")]='\0';
    getchar();
    system("clear");
    for(int i=0;i<5;i++){
        system("clear");
        char enter[100],type[100];
        time_t start,stop;
        char* wordList[]={"Hello", "Bye", "Car", "Dragon", "Program", "Gaming", "Movies", "Website", "Good", "Bad",
        "He!!o","Bye!@#","Car123","Web12!","Anime!@12","!@Cool#$","12Bill!@","MessySassy","CoolFool","AmAzInG"
        "BAka!@HAka","haKA@!baKA","Smarty!@#Lasty","No12Bil","NastyMasty","KillBill","SwordGun","M1g43","G12gsn!@","FunkyMonkey", "JazzHands", "NoodleSoup", "ZanyBrainy", "PixelPunk", "TurboTaco", "MegaMuffin", "SillyGoose",
        "BananaSplit", "WackyTacky", "LoopyLlama", "QuirkyTurkey", "JollyJelly", "DizzyLizzy", "CrazyLazy", "SnappyHappy",
        "ChocoLoco", "BongoFongo", "WhackySnacky", "FizzBuzz", "JumpyBumpy", "GiggleWiggle", "PlasmaBlaster", "RocketSock",
        "ZippyZappy", "TurboSlurpee", "FunkyChunky", "WobbleGobble", "SneakyBeaky", "GoofyLoofy", "MangoTango", "BubbleTrouble",
        "SnickerDoodle", "TwistyFisty", "X7R9K2", "Alpha123", "Beta_007", "Cyber42", "DeltaX5", "Echo9", "Foxtrot8", "Gamma12",
        "Hyper5", "Ion3", "Jupiter88", "Kappa1", "Lambda777", "Mega9000", "Nova5", "Omega42",
        "Pixel99", "QuantumX", "Robo3", "Sigma4", "Techno007", "Ultra5", "Vector12", "Warp9",
        "Xeno7", "Yotta88", "Zeta42", "Aero10", "Blaze99", "Crash5", "DroidX", "Echo7",
        "Flux3000", "Glitch9", "Hexa8", "Ignite21", "Jinx7", "Krypto3", "Lunar42", "Matrix99",
        "Neon5", "OrbitX", "Pulse007", "Quark8", "Rocket21", "Surge9", "TurboX", "Volt3",
        "WarpSpeed", "Xcalibur7", "Zenith42","Neo!Gen7", "Flash#X2", "Omega@Pulse", "Sky!Net9", "Cyber^Core", "Glitch#42", "Alpha*Ray",
        "Zero!One", "Dark#Wolf", "Iron@Clad", "Vortex^9", "Quantum*Leap", "Solar!Flare", "Pixel#Rush",
        "Nexus@5", "Phantom^X", "Titan*Force", "Crimson!Edge", "Blade#Runner", "Shadow@Zone",
        "Echo^Base", "Nova*Star", "Rogue!Agent", "Stellar#Wind", "Turbo@Drive", "Venom^Strike",
        "Wolf*Pack", "Zenith!Point", "Blaze#Fire", "Circuit@Break", "Dynamo^Power", "Eclipse*Sun",
        "Frost!Byte", "Gravity#Fall", "Horizon@Line", "Ignite^Spark", "Jolt*Shock", "Karma!Wave",
        "Lunar#Glow", "Mystic@Fog", "Nimbus^Cloud", "Onyx*Shadow", "Pulse!Beat", "Quasar#Light",
        "Radiant@Flux", "Sonic^Boom", "Tempest*Storm", "Ultra!Violet", "Vector#Shift", "Warden@Guard",
        "Xenon^Flash", "Yield*Force","X9v!rT3", "Qw3rTy#7", "Z1pL0ck@", "N8mB3r$5", "V0lt@ge12", "T1m3!Warp", "F1r3&Ice", "Gl0w#Up",
        "Sn4pSh0t!", "P1xel*Art", "Bl1tz$X9", "H4ck3r!z", "Cr4zy^Code", "M0n5t3r#", "S0lar!Flare",
        "J3tP@ck42", "F0xT@il9", "R@z0rBlade", "K1ngC0d3r", "B0unc3!It", "L0g1c^Flow", "Turb0#Spin",
        "C0d3Cr@ft", "V1r@lW@v3", "N3tw0rk!X", "Sh@d0w9z", "M3t@P0ly", "W@rP1pe7", "Fl@shC0d3",
        "Cyb3r!N1n", "Sp@rkPlug", "Bl@z1ngX", "D@rkN3ss7", "V@mp!r3z", "Ph@nt0mX1", "Cr@z3y#7",
        "Q1u3tSt0rm", "Z3r0*Cool", "G@l@xy1", "F1r3fly#", "N1ghtOw1", "C@lmBreez3", "L@serTag9",
        "T3rr0r!X", "S1lv3r$hot", "P@r@d0x7", "V1r!dian", "M@dr1d$un", "N0mad!C1", "S@ndSt0rm",
        "Xtr3m3P0w3r", "Bl@ckM@giC"
        };
        int word_length=sizeof(wordList)/sizeof(wordList[0]);
        int wordNum= rand()%word_length;
        char* word=wordList[wordNum];
        puts(M B I"AI Will Show You A Word !!! Let See How Fast You Observe and Remember the Thing");
        sleep(4);
        printf(W"%s",word);
        fflush(stdout);
        sleep(2);
        puts("\n");
        system("clear");
        time(&start);
        printf(R "\t\t\t\033[4mRound %d\033[0m\n",i+1);
        printf(B W I"Enter the Word : ");
        fgets(type,sizeof(type),stdin);
        type[strcspn(type,"\n")]='\0';
        time(&stop);
        if(strcmp(type,"Q")==0||strcmp(type,"q")==0){
            system("clear");
            prtext(B I W "🤖 AI: Hahaha! Did I scare you already, human? Run while you can!\n");
            printf(M B I "🪖 Commander: Stand tall, soldier! We don’t quit like losers!!!\n" r);
            sleep(2);
            system("clear");
            break;
        }
        if (strcmp(type,word)==0){
            printf(G"You Got A Pretty Sharp Memory and Good Observing Skills!!!\n");
            printf("Time Taken To Type The Word %.2f Second \n",difftime(stop,start));
            score++;
            timetaken+=difftime(stop,start);
            sleep(2);
            system("clear"r);
        } 
        else {
            printf(R "Bad Memory and Observation!!! You Need To Improve\n");
            printf("The Word Was : %s\n",word);
            printf("Time Taken To Type The Word %.2f Second \n",difftime(stop,start));
            timetaken+=difftime(stop,start);
            sleep(2);
            system("clear"r);
        }
    }
    if(score>=4){
        system("clear");
        prtext(B C I"🤖 AI : I Am Impressed!!! It's Great To See People Like You Who Have Great Skill Like Me!!!\n");
        printf("🪖 Commander: Great Work Soldier!!! You Will Be Kids' Inspiration\n");
        puts(R "\n\t\033[4mScore Board\033[0m");
        printf(G B I"\t|------------------|\n");
        printf("\t| Round      :  5  |\n");
        printf("\t| Your Score :  %d  |\n",score);
        printf("\t|------------------|\n\n"r);
        printf(W B I"Total Time Taken : %d seconds\n\n",timetaken);
        printf("Press Enter To Skip....."r);
        getchar();
        system("clear");
    }
    else if(score>=2){
        system("clear");
        prtext(Y B I"🤖 AI : Not Bad!!! But You Can't Reach My Level\n");
        printf("🪖 Commander: No Worries Soldier!! Work Hard Next Time\n");
        puts(R "\n\t\033[4mScore Board\033[0m");
        printf(G B I"\t|------------------|\n");
        printf("\t| Round      :  5  |\n");
        printf("\t| Your Score :  %d  |\n",score);
        printf("\t|------------------|\n\n"r);
        printf(W B I"Total Time Taken : %d seconds \n\n",timetaken);
        printf("Press Enter To Skip....."r);
        getchar();
        system("clear");
    }
    else{
        system("clear");
        prtext(R B I"🤖 AI : Oops! Memory loss detected... Did you leave your brain back at base? HAHAHA.....\n");
        printf("🪖 Commander: Train harder, soldier! Or you might end up stuck in boot camp forever!\n");
        puts(R "\n\t\033[4mScore Board\033[0m");
        printf(G B I"\t|------------------|\n");
        printf("\t| Round      :  5  |\n");
        printf("\t| Your Score :  %d  |\n",score);
        printf("\t|------------------|\n\n"r);
        printf(W B I"Total Time Taken : %d second \n\n",timetaken);
        printf("Press Enter To Skip....."r);
        getchar();
        system("clear");
    }
}

// Main Body
int main(){
    connectionRequest();
    do{
        intro();
        srand(time(0));
        char number[10],replay[5];
        puts(W B I"🪖 Commander: ⚠️ Attention, soldier. This is Command. ");
        puts("🪖 Commander: You have been selected for Mission: Defeat the AI."); 
        printf("🪖 Commander: Enter your mission code: "r);
        fgets(number,sizeof(number),stdin);
        number[strcspn(number,"\n")]='\0';
        if (number[0]=='q'||number[0]=='Q')
        {
            system("clear");    // Use clear for Linux and Mac, and cls for Windows to clear the terminal screen.
            printf(B I"Even the toughest soldier needs a break.\nCatch you later, Solider!!!\n\n"r);
            disconnectRequest();
            // sleep(5);           // Use 5 seconds delay for Linux and Mac, and 5000 milliseconds (5 seconds) for Windows.
            // system("clear");    // Use clear for Linux and Mac, and cls for Windows to clear the terminal screen.
            break;
        }
        if(strlen(number)==1)
        {
            switch(number[0])
            {
                case '1':     system("clear");
                              prtext(W B I"Loading Your Mission"r);
                              loadScreen(12);
                              do{
                              system("clear");
                              rockPaperScissor();
                              system("clear");
                              printf(B I"Press 'Y' To Replay Or Any Other Key To Return To The Main Menu..."r);
                              fgets(replay,sizeof(replay),stdin);
                              replay[strcspn(replay,"\n")]='\0';
                              if(replay[0]=='Y'||replay[0]=='y'){
                                  
                              }
                              else{
                                  system("clear");
                                  printf(b B I"Redirecting TO Main Menu.......... "r);
                                  loadPercentage(12);
                                  system("clear");
                                  break;
                              }
                          }while(replay[0]=='Y'||replay[0]=='y');
                          break;
                case '2':     system("clear");
                              prtext(B I"Loading Your Mission"r);
                              loadScreen(15);
                              do{
                              system("clear");
                              guessTheNumber();
                              system("clear");
                              printf(B I"Press 'Y' To Replay Or Any Other Key To Return To The Main Menu..."r);
                              fgets(replay,sizeof(replay),stdin);
                              replay[strcspn(replay,"\n")]='\0';
                              if(replay[0]=='Y'||replay[0]=='y'){
                                  
                              }
                              else{
                                  system("clear");
                                  printf(b B I"Redirecting TO Main Menu.......... "r);
                                  loadPercentage(12);
                                  system("clear");
                                  break;
                              }
                          }while(replay[0]=='Y'||replay[0]=='y');
                          break;
                case '3':     system("clear");
                              prtext(B I"Loading Your Mission"r);
                              loadScreen(12);do{
                              system("clear");
                              snakeWaterGun();
                              system("clear");
                              printf(B I"Press 'Y' To Replay Or Any Other Key To Return To The Main Menu..."r);
                              fgets(replay,sizeof(replay),stdin);
                              replay[strcspn(replay,"\n")]='\0';
                              if(replay[0]=='Y'||replay[0]=='y'){
                                  
                              }
                              else{
                                  system("clear");
                                  printf(b B I"Redirecting TO Main Menu.......... "r);
                                  loadPercentage(12);
                                  system("clear");
                                  break;
                              }
                          }while(replay[0]=='Y'||replay[0]=='y');
                          break;
                case '4':     system("clear");
                              prtext(B I"Loading Your Mission"r);
                              loadScreen(18);do{
                              system("clear");
                              headTail();
                              system("clear");
                              printf(B I"Press 'Y' To Replay Or Any Other Key To Return To The Main Menu..."r);
                              fgets(replay,sizeof(replay),stdin);
                              replay[strcspn(replay,"\n")]='\0';
                              if(replay[0]=='Y'||replay[0]=='y'){
                                  
                              }
                              else{
                                  system("clear");
                                  printf(b B I"Redirecting TO Main Menu.......... "r);
                                  loadPercentage(12);
                                  system("clear");
                                  break;
                              }
                          }while(replay[0]=='Y'||replay[0]=='y');
                          break;
                case '5':     system("clear");
                              prtext(B I"Loading Your Mission"r);
                              loadScreen(15);
                              do{
                              system("clear");
                              memoryTest();
                              system("clear");
                              printf(B I"Press 'Y' To Replay Or Any Other Key To Return To The Main Menu..."r);
                              fgets(replay,sizeof(replay),stdin);
                              replay[strcspn(replay,"\n")]='\0';
                              if(replay[0]=='Y'||replay[0]=='y'){
                                  
                              }
                              else{
                                  system("clear");
                                  printf(b B I"Redirecting TO Main Menu.......... "r);
                                  loadPercentage(12);
                                  system("clear");
                                  break;
                              }
                          }while(replay[0]=='Y'||replay[0]=='y');
                          break;
                default:
                        system("clear");
                        prtext(Y B I"\a⚠️ That number? Game Over-worthy. Insert brain and try again!\n"r);
                        sleep(2);
                        system("clear");
            }
        }
        else
        {
            system("clear");    // Use clear for Linux and Mac, and cls for Windows to clear the terminal screen.
            printf(Y B I"\a⚠️ WARNING! ⚠️\nAre you serious, Soldier?! This time, press a VALID number to enter the grid!\n");
            printf("\aNo funny business, or it's push-ups for you!\n"r);
            sleep(5);           // Use 5 seconds delay for Linux and Mac, and 5000 milliseconds (5 seconds) for Windows.
            system("clear");    // Use clear for Linux and Mac, and cls for Windows to clear the terminal screen.
        }
    }while(1);
}
