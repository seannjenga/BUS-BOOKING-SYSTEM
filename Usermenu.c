void display  UserMenu()

{
    printf("\n === User Menu=== \n");
    printf("1. Book a Ticket\n"); 
	printf("2. Cancel a Ticket\n"); 
	printf("3. Check Bus Status\n"); 
	printf("4. Logout\n"); 
	printf("Enter your choice: "); 
}

int loginUser(struct User users[], int numUsers, 
			char username[], char password[]) 
{ 
	for (int i = 0; i < numUsers; i++) { 
		if (strcmp(users[i].username, username) == 0 
			&& strcmp(users[i].password, password) == 0) { 
			return i; // Return the index of the logged-in 
					// user 
		} 
	} 
	return -1; // Return -1 if login fails 
} 


// Initialize bus data 
	struct Bus buses[3] = {{ 
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