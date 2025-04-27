#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TOTAL_QUESTIONS 30
#define QUESTIONS_TO_ASK 10

typedef struct {
    char question[256];
    char options[4][100];
    char correctOption;
} Question;

void betterShuffle(int *array, int n, int salt) {
    for (int i = n - 1; i > 0; i--) {
        int swapIndex = (i * 17 + salt * 31) % n;
        int temp = array[i];
        array[i] = array[swapIndex];
        array[swapIndex] = temp;
    }
}

int main() {
    Question quiz[TOTAL_QUESTIONS] = {
        {"What is the capital of France?", {"A. Paris", "B. London", "C. Berlin", "D. Rome"}, 'A'},
        {"Which planet is known as the Red Planet?", {"A. Earth", "B. Mars", "C. Jupiter", "D. Venus"}, 'B'},
        {"What is the chemical symbol for water?", {"A. CO2", "B. H2O", "C. O2", "D. HO2"}, 'B'},
        {"Who wrote 'Hamlet'?", {"A. Charles Dickens", "B. J.K. Rowling", "C. William Shakespeare", "D. Jane Austen"}, 'C'},
        {"Which organ pumps blood in the human body?", {"A. Brain", "B. Heart", "C. Liver", "D. Kidney"}, 'B'},
        {"What is 9 x 9?", {"A. 81", "B. 72", "C. 99", "D. 89"}, 'A'},
        {"Which is the largest planet in our solar system?", {"A. Earth", "B. Saturn", "C. Jupiter", "D. Mars"}, 'C'},
        {"What gas do plants absorb?", {"A. Oxygen", "B. Hydrogen", "C. Carbon Dioxide", "D. Nitrogen"}, 'C'},
        {"Who invented the light bulb?", {"A. Alexander Graham Bell", "B. Nikola Tesla", "C. Thomas Edison", "D. Isaac Newton"}, 'C'},
        {"Which language is used to create websites?", {"A. HTML", "B. C", "C. Python", "D. Java"}, 'A'},
        {"How many continents are there?", {"A. 5", "B. 6", "C. 7", "D. 8"}, 'C'},
        {"What is the freezing point of water in Celsius?", {"A. 0", "B. 32", "C. 100", "D. -10"}, 'A'},
        {"Which country is famous for pizza?", {"A. Spain", "B. Italy", "C. Greece", "D. India"}, 'B'},
        {"Which animal is called the 'King of the Jungle'?", {"A. Tiger", "B. Lion", "C. Elephant", "D. Leopard"}, 'B'},
        {"How many legs does a spider have?", {"A. 6", "B. 8", "C. 10", "D. 12"}, 'B'},
        {"Which is the smallest prime number?", {"A. 0", "B. 1", "C. 2", "D. 3"}, 'C'},
        {"What do bees produce?", {"A. Sugar", "B. Wax", "C. Honey", "D. Nectar"}, 'C'},
        {"Which ocean is the deepest?", {"A. Atlantic", "B. Indian", "C. Arctic", "D. Pacific"}, 'D'},
        {"Which is the largest continent?", {"A. Africa", "B. Asia", "C. Europe", "D. Australia"}, 'B'},
        {"What color is chlorophyll?", {"A. Red", "B. Blue", "C. Yellow", "D. Green"}, 'D'},
        {"Which is the fastest land animal?", {"A. Lion", "B. Tiger", "C. Cheetah", "D. Gazelle"}, 'C'},
        {"Which element has the chemical symbol 'O'?", {"A. Oxygen", "B. Gold", "C. Silver", "D. Iron"}, 'A'},
        {"Who is the founder of Microsoft?", {"A. Steve Jobs", "B. Bill Gates", "C. Elon Musk", "D. Mark Zuckerberg"}, 'B'},
        {"Which is the smallest ocean?", {"A. Atlantic", "B. Indian", "C. Arctic", "D. Pacific"}, 'C'},
        {"How many players are there in a football (soccer) team?", {"A. 9", "B. 10", "C. 11", "D. 12"}, 'C'},
        {"What is the capital of Japan?", {"A. Kyoto", "B. Osaka", "C. Tokyo", "D. Hiroshima"}, 'C'},
        {"Which country is known as the Land of the Rising Sun?", {"A. Japan", "B. China", "C. Korea", "D. India"}, 'A'},
        {"Which bird is a symbol of peace?", {"A. Eagle", "B. Pigeon", "C. Dove", "D. Sparrow"}, 'C'},
        {"What is the hardest natural substance?", {"A. Gold", "B. Iron", "C. Diamond", "D. Platinum"}, 'C'},
        {"Which blood group is known as universal donor?", {"A. A", "B. B", "C. AB", "D. O"}, 'D'}
    };

    int indices[TOTAL_QUESTIONS];
    char playAgain;
    int gameSession = 1;

    do {
        for (int i = 0; i < TOTAL_QUESTIONS; i++) {
            indices[i] = i;
        }

        betterShuffle(indices, TOTAL_QUESTIONS, gameSession);

        int score = 0;
        char answer;

        printf("\n=============================\n");
        printf("     Welcome to the Quiz     \n");
        printf("=============================\n\n");

        for (int i = 0; i < QUESTIONS_TO_ASK; i++) {
            int qIndex = indices[i];
            printf("Q%d) %s\n", i + 1, quiz[qIndex].question);
            printf("\t%s\n", quiz[qIndex].options[0]);
            printf("\t%s\n", quiz[qIndex].options[1]);
            printf("\t%s\n", quiz[qIndex].options[2]);
            printf("\t%s\n", quiz[qIndex].options[3]);
            
            printf("\nYour answer (A/B/C/D): ");
            scanf(" %c", &answer);

            answer = toupper(answer);

            if (answer == quiz[qIndex].correctOption) {
                printf("Correct!\n\n");
                score++;
            } else {
                printf("Wrong! Correct answer: %c\n\n", quiz[qIndex].correctOption);
            }

            printf("-----------------------------\n");
        }

        printf("\n=============================\n");
        printf("         Quiz Over!          \n");
        printf("=============================\n");
        printf("Your final score is: %d / %d\n", score, QUESTIONS_TO_ASK);
        printf("=============================\n");

        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
        playAgain = toupper(playAgain);
        gameSession++;

    } while (playAgain == 'Y');

    printf("\nThank you for playing!\n");

    return 0;
}
