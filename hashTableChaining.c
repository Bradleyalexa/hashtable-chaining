//hash table chaining collision handling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int tableSize = 10;

struct hashNode {
	char key[100];
	int value;
	struct hashNode *next;
};

void show(struct hashNode *hashTable[]){
	int i;
	struct hashNode *temp = NULL;
	for(i = 0; i < tableSize; i++){
		temp = hashTable[i];
		printf("[index ke-%d] ", i);
		while(temp != NULL){
			printf("%s, %d -> ", temp->key, temp->value);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}

void insert(char *key, int value, struct hashNode *hashTable[]){
	struct hashNode *new_node = (struct hashNode*)malloc(sizeof(struct hashNode));
	strcpy(new_node->key, key);
	new_node->value = value;
	new_node->next = NULL;

	//perlu ambil ASCII untuk Key. karena mau nentuin Index di table
	int keyInt = convertStringToInt(key);
	int index = hashDivision(keyInt);

	struct hashNode *temp = hashTable[index];

	if(hashTable[index] == NULL){
		hashTable[index] = new_node;
	}else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new_node;
	}
}

int hashDivision (int ascii){
	return ascii % tableSize;
}

int convertStringToInt(char *key){
	int stringLength = strlen(key);
	int ascii = 0;
	int i;
	for (i=0; i < stringLength; i++){
		ascii += key[i];
	}
	return ascii;
}

int retrieve(char *key, struct hashNode *hashTable[]){
	int keyInt = convertStringToInt(key);
	int index = hashDivision(keyInt);
	struct hashNode *temp = NULL;

	temp = hashTable[index];
	while(temp != NULL){
		if (strcmp(temp->key, key) == 0){
			printf("%s, %d\n", temp->key, temp->value);
			return temp->value;
		}
		temp = temp->next;
	}
	printf("not found");
	return 0;
}

int main(){
	struct hashNode *hashTable[tableSize];
	int i;
	for (i = 0; i < tableSize; i++){
		hashTable[i] = NULL;
	}

	insert("Arif", 10, hashTable);
	insert("Budi", 11, hashTable);
	insert("Citra", 12, hashTable);
	insert("Dwi", 13, hashTable);
	insert("Fajar", 14, hashTable);
	insert("Kurniawan", 15, hashTable);
	insert("Indah", 16, hashTable);
	insert("Hidayat", 17, hashTable);
	show(hashTable);

	int value = retrieve("Fadlan", hashTable);
	return 0;
}
