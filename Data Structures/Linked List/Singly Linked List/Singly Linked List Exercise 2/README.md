# Sign: Analysing Signature Data

A signature is a way a person signs their signature. The signature collection using a digital tablet represented a set of data packets tracking pen movements in time. In this assignment, your task is to implement a C program that can be used to analyze and interpret processed signature data collected using a Wacom Digital Tablet. 
:rocket:

### :memo: Problem Definition

In this program, you will need first to import processed signature data in the format shown in the table below.



| UserName | Pen Up | Width | Height | Velocity X | Velocity Y | Pressure |
| -------- | ------ | ----- | ------ | ---------- | ---------- |:--------:|
| User1    | 4      | 6373  | 1840   | 2.75       | -0.27      |  530.90  |
| User2    | 4      | 6770  | 2597   | 3.82       | 0.09       |  459.81  |
| User2    | 4      | 6890  | 2295   | 3.93       | -0.69      |  492.41  |
| ...      | ...    | ...   | ...    | ...        | ...        |   ...    |
| User5    | 5      | 7925  | 2713   | 3.69       | -0.63      |  592.75  |


The table above shows the processed signature of a user, specifically a series of information about how the user signs their signature. This information is referred to as features. Each line of the table shows the features of the signature signed by the user. For each user signature, the following details are provided: Pen Up (number of times the user holds the pen up while signing), Width (width of the signature), Height (height of the signature), Velocity X (the velocity of the signing in the x-direction), Velocity Y (the velocity of the signing in the y-direction), Pressure (pressure of the pen while signing).

Read processed signature data and represent it in the program as follows: a linked list should be created to store the users, and for each user, a linked list needs to be created where each node stores information about a particular signature feature (i.e., about each entry in the given the table above).

Once processed signature data from a file, implementation of some basic operations of linked lists are needed, such as the insertion and deletion of nodes, once the required data structure with its primary functions is created, some statistics need to be provided about the signature data to the users and allow them to interact with your application given below.

### :pushpin: Programming Requirements

First, you need to define a data structure to represent the data structure given in Figure 1. Please note that you need to use a linked list to describe the signature features for each user, and you will need another one to keep track of these linked lists. You should not make any assumption about the number of signature features recorded for a particular user, and also, you should not make any assumption about the number of users. Your program will need to follow these steps: 
1) You need to read signature data from an external text file. Please note that you cannot make an assumption about the number of signatures in a file. Assume that the file is given in the format in the table. Assume that a comma separates the data in the file. For instance, User1,4,6373,1840,2.75,-0.27,530.90 
2) You will need to create the data structure in Figure 1 to represent the list of signature features for each user.
3) You will then ask the users whether they would like to remove the data or not. If they would like to remove the data, the program will ask them to enter a threshold value for a pressure value, and you will then delete all the signatures below that pressure. 
4) You will then display the following statistics to the user: 
    * a. The number of signatures for a particular user is the number of nodes created for a specific user. 
    * b. The average pressure for a particular user. To achieve these steps, you need to have the following functions. 



* **load_data:** This function will take the file name as an input. It will then load the data from the file to your data structure defined in Figure 1. This function will return this data structure. 
    * input: file name that will be used to load signatures 
    * return: a data structure to represent the overall data, see Figure 1

* **remove_signature:** This function will take the data structure represented in Figure 1 and a threshold value. It will then remove all the nodes from all users with pressure below that threshold value. 
    * input: a data structure to represent the overall data see Figure 1 
    * return: void

* **average_pressure:** This function will get a linked list of signature features recorded for a user, and it will return the average pressure feature in that list. 
    * input: a linked list of signature features for a particular user 
    * return: The average pressure of signatures

* **count_signatures:** This function will get a linked list of signature features recorded for a user, and it will return the number of signatures (i.e., nodes) in that list.
    * input: a linked list of signature features for a particular user
    * return: The number of signatures

### Sample Run

```
Sign: Analysing Signature Data
Enter file name: P1.txt
The signature features is successfully loaded.
------------------------------------------------
Sign Menu
-----------------------
1. Remove Signatures
2. Show User Statistics
3. Exit from Sign
------------------------------------------------
Enter your option: 1
Enter a threshold value: 500.0
The number of fixations removed: 2
------------------------------------------------
Sign Menu
-----------------------
1. Remove Signatures
2. Show User Statistics
3. Exit from Sign
------------------------------------------------
Enter your option: 2
Enter a user name: user1
The number of signatures: 1
The total pen pressure: 530.90
------------------------------------------------
Sign Menu
-----------------------
1. Remove Signatures
2. Show User Statistics
3. Exit from Sign
------------------------------------------------
Enter your option: 3
Goodbye!
```
