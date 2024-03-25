#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <libc.h>

// Structures section
struct Race {
    int numberOfLaps;
    int currentLap;
    char firstPlaceDriverName[15];
    char firstPlaceRaceCarColor[11];
};

struct RaceCar {
    char driverName[14];
    char raceCarColor[10];
    int totalLapTime;
};

// Print functions section
void printIntro();
void printCountDown();
void printFirstPlaceAfterLap(struct Race);
void printCongratulation(struct Race);

// Logic functions section
int calculateTimeToCompleteLap();
void updateRaceCar(struct RaceCar*);
void updateFirstPlace(struct Race*, struct RaceCar*, struct RaceCar*);
void startRace(struct RaceCar*, struct RaceCar*);

int main() {
    srand(time(0)); // <Slaps own hand> Yes, I know srand's bad, but it doesn't need to be good for this application.
    struct RaceCar raceCar1 = {.driverName = "Scooby", .raceCarColor = "Red"};
    struct RaceCar raceCar2 = {.driverName = "Shaggy", .raceCarColor = "Green"};
    printIntro();
    printCountDown();
    startRace(&raceCar1, &raceCar2);
}

// Print functions implementation
void printIntro() {
    printf("Welcome to our main event digital race fans!\n");
    printf("I hope everybody has their snacks because we are about to begin!\n");
}

void printCountDown() {
    printf("\nRacers Ready! In...\n");
    for (int i = 5; i > 0; i--) {
        printf("%i\n", i);
    }
    printf("Race!\n");
}

void printFirstPlaceAfterLap(struct Race race) {
    printf("After lap number %i\n", race.currentLap);
    printf("First Place Is: %s in the %s race car!\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race) {
    printf("Let's all congratulate %s in the %s race car for an amazing performance.\n", race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
    printf("It truly was a great race and everybody have a goodnight!");
}

// Logic functions implementation
int calculateTimeToCompleteLap() {
    int speed = (rand() % 3) + 1;
    int acceleration = (rand() % 3) + 1;
    int nerves = (rand() % 3) + 1;
    return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar) {
    raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
    if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
        strcpy(race->firstPlaceDriverName, raceCar1->driverName);
        strcpy(race->firstPlaceRaceCarColor, raceCar1->raceCarColor);
    } else {
        strcpy(race->firstPlaceDriverName, raceCar2->driverName);
        strcpy(race->firstPlaceRaceCarColor, raceCar2->raceCarColor);
    }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
    struct Race race = {.numberOfLaps = 5, .currentLap = 1, .firstPlaceDriverName = "", .firstPlaceRaceCarColor = ""};

    for (int i = 0; i < race.numberOfLaps; ++i) {
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);
        updateFirstPlace(&race, raceCar1, raceCar2);
        printFirstPlaceAfterLap(race);
        race.currentLap++;
    }
    printCongratulation(race);
}