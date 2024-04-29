#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototype to interact with backend
void addItemToBackend(struct AuctionItem *item);

// Structure to hold Auction Item details
struct AuctionItem {
    int itemId;
    char itemName[50];
    float currentBid;
};

// Wrapper function to add item to backend
void addItemToBackend(struct AuctionItem *item) {
    // Execute the backend executable and pass the item details as arguments
    char command[256];
    sprintf(command, "a.exe %d \"%s\" %.2f", item->itemId, item->itemName, item->currentBid);
    system(command);
}

int main() {
    // Example usage:
    struct AuctionItem newItem;
    newItem.itemId = 123;
    strcpy(newItem.itemName, "Example Item");
    newItem.currentBid = 100.0;

    // Add item to backend
    addItemToBackend(&newItem);

    return 0;
}
