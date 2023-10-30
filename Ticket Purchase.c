// Function to book a ticket 
void bookTicket(struct Bus buses[], int numBuses, 
				struct Passenger passengers[], 
				int* numPassengers, int userId) 
{ 
	printf("\nEnter Bus Number: "); 
	int busNumber; 
	scanf("%d", &busNumber);

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

        	// Assign a seat number to the passenger 
		passengers[*numPassengers].seatNumber 
			= buses[busIndex].totalSeats 
			- buses[busIndex].availableSeats + 1; 

		// Update the passenger's bus number 
		passengers[*numPassengers].busNumber = busNumber; 

		// Update available seats 
		buses[busIndex].availableSeats--; 

		printf("Ticket booked successfully!\n"); 
		(*numPassengers)++; 
	} 
} 

