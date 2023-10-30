// Function to cancel a ticket 
void cancelTicket(struct Bus buses[], int numBuses, 
				struct Passenger passengers[], 
				int* numPassengers, int userId) 
{ 
	printf("\nEnter Passenger Name: "); 
	char name[50]; 
	scanf("%s", name); 

	int found = 0; 
	for (int i = 0; i < *numPassengers; i++) { 
		if (strcmp(passengers[i].name, name) == 0 
			&& passengers[i].busNumber 
				== buses[userId].busNumber) { 
			// Increase available seats 
			int busIndex = -1; 
			for (int j = 0; j < numBuses; j++) { 
				if (buses[j].busNumber 
					== passengers[i].busNumber) { 
					busIndex = j; 
					break; 
				} 
			} 
			buses[busIndex].availableSeats++; 

			// Remove the passenger entry 
			for (int j = i; j < (*numPassengers) - 1; j++) { 
				passengers[j] = passengers[j + 1]; 
			} 
			(*numPassengers)--; 
			found = 1; 
			printf("Ticket canceled successfully!\n"); 
			break; 
		} 
	} 
	if (!found) { 
		printf("Passenger with name %s not found on this "
			"bus.\n", 
			name); 
	} 
} 

