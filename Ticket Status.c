// Function to check bus status 
void checkBusStatus(struct Bus buses[], int numBuses, 
					int userId) 
{ 
	printf("\nBus Number: %d\n", buses[userId].busNumber); 
	printf("Source: %s\n", buses[userId].source); 
	printf("Destination: %s\n", buses[userId].destination); 
	printf("Total Seats: %d\n", buses[userId].totalSeats); 
	printf("Available Seats: %d\n", 
		buses[userId].availableSeats); 
	printf("Fare: %.2f\n", buses[userId].fare); 
} 
