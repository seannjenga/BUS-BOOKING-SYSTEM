#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definbe a structure to store Bus Information
struct Bus {
int bus Number;
char source;
char destination[50];
int totalSeats;
int availableSeats;
float fare;

};

	// Find the bus with the given busNumber 
	int busIndex = -1; 
	for (int i = 0; i < numBuses; i++) { 
		if (buses[i].busNumber == busNumber) { 
			busIndex = i; 
			break; 
		} 
	} 

	if (busIndex == -1) { 
		printf("Bus with Bus Number %d not found.\n", 
			busNumber); 
	} 
	else if (buses[busIndex].availableSeats == 0) { 
		printf("Sorry, the bus is fully booked.\n"); 
	} 
	else { 
		printf("Enter Passenger Name: "); 
		scanf("%s", passengers[*numPassengers].name); 

		printf("Enter Passenger Age: "); 
		scanf("%d", &passengers[*numPassengers].age);


        // Initialize bus data 
	struct Bus buses[3] = { 
		{ 101, "Nairobi", "Nakuru", 50, 50, 25.0 }, 
		{ 102, "Naivasha", "Mombasa", 40, 40, 20.0 }, 
		{ 103, "Kisumu", "Kilifi", 30, 30, 15.0 }, 
	}; 
	int numBuses = 3; 

	struct Passenger 
		passengers[500]; // Array to store passenger 
						// information 
	int numPassengers = 0; // Number of passengers 

	int loggedInUserId = -1; // Index of the logged-in user 

	while (1) { 
		if (loggedInUserId == -1) { 
			displayMainMenu(); 
			int choice; 
			scanf("%d", &choice); 

			if (choice == 1) { 
				char username[50]; 
				char password[50]; 

				printf("Enter Username: "); 
				scanf("%s", username); 
				printf("Enter Password: "); 
				scanf("%s", password); 

				loggedInUserId = loginUser( 
					users, numUsers, username, password); 
				if (loggedInUserId == -1) { 
					printf("Login failed. Please check "
						"your username and password.\n"); 
				} 
				else { 
					printf( 
						"Login successful. Welcome, %s!\n", 
						username); 
				} 
			} 
			else if (choice == 2) { 
				printf("Exiting the program.\n"); 
				break; 
			} 
			else { 
				printf( 
					"Invalid choice. Please try again.\n"); 
			} 
		} 
		else { 
			displayUserMenu(); 
			int userChoice; 
			scanf("%d", &userChoice); 

			switch (userChoice) { 
			case 1: 
				bookTicket(buses, numBuses, passengers, 
						&numPassengers, loggedInUserId); 
				break; 
			case 2: 
				cancelTicket(buses, numBuses, passengers, 
							&numPassengers, 
							loggedInUserId); 
				break; 
			case 3: 
				checkBusStatus(buses, numBuses, 
							loggedInUserId); 
				break; 
			case 4: 
				printf("Logging out.\n"); 
				loggedInUserId = -1; 
				break; 
			default: 
				printf( 
					"Invalid choice. Please try again.\n"); 
			} 
		} 
	} 

	return 0; 
}