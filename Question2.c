//treasure hunt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for each clue
struct Clue {
    char hint[100];
    struct Clue* next;
};

struct Clue* head = NULL;

// Add a clue at the end
void addClue(char* hintText) {
    struct Clue* newClue = (struct Clue*)malloc(sizeof(struct Clue));
    strcpy(newClue->hint, hintText);
    newClue->next = NULL;

    if (head == NULL) {
        head = newClue;
    } else {
        struct Clue* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newClue;
    }

    printf("Clue added: %s\n", hintText);
}

// Display all clues (debugging or organizer view)
void displayClues() {
    struct Clue* temp = head;
    int i = 1;

    if (temp == NULL) {
        printf("No clues in the hunt.\n");
        return;
    }

    printf("All Clues in the Hunt:\n");
    while (temp != NULL) {
        printf("Clue %d: %s\n", i++, temp->hint);
        temp = temp->next;
    }
}

// Simulate the hunt (step-by-step)
void startHunt() {
    struct Clue* temp = head;
    int step = 1;

    if (temp == NULL) {
        printf("No clues to start the hunt.\n");
        return;
    }

    printf("Starting the Treasure Hunt!\n");
    while (temp != NULL) {
        printf("Step %d: %s\n", step++, temp->hint);
        temp = temp->next;
    }

    printf("🎉 You found the treasure! 🎉\n");
}

int main() {
    int choice;
    char clue[100];

    do {
        printf("\n1. Add Clue\n2. Display Clues\n3. Start Hunt\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter clue: ");
                fgets(clue, sizeof(clue), stdin);
                clue[strcspn(clue, "\n")] = 0;
                addClue(clue);
                break;
            case 2:
                displayClues();
                break;
            case 3:
                startHunt();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
