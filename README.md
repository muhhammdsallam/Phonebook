# Phonebook
Introduction & Background
This user friendly program is designed to help the user to manage any contact list loaded from a certain file, our main goal in this program is to make it easy for the user to access his contact list and be able to:

1.	Add contact to his contact list.
2.	Delete any contacted wanted from his list.
3.	Search for any contact by using many options.
4.	Modifying any aspect in any contact he searched for.
5.	Print sorted contacts according to choosable aspect.
6.	Save all your progress in any time you want.

To help us achieve our goal we used specific functions and certain algorithms that will be mentioned later.
So, without further ado, here’s the program’s manual.  

 
# Project manual
As mentioned before the program is designed to perform certain tasks.  So, this part shows how the program works and how to use it.
First of all the program starts by loading the contacts from default file , then a list of all tasks is printed on the screen with the number of contacts in the file as follows:


![image](https://user-images.githubusercontent.com/81472165/116831202-33675000-abae-11eb-9cf4-66b994562b66.png)


		
 The tasks are as follows:


# 1-Search contact

This function is used to look for any specific contact in your list and print all the     contacts found.
The function starts when you press the letter ‘S’ --doesn’t matter either upper case or lower case--, when you press ‘S’ another list of options appear which is the “search by” list where you choose what to search with:



![image](https://user-images.githubusercontent.com/81472165/116831209-3d894e80-abae-11eb-8d06-fadb1816f0a2.png)






The options are:
1-  Searching by First name accessed by pressing ‘F’
2-  Searching by Last name accessed by pressing ‘L’
3-  Searching by Email address accessed by pressing ‘E’
4-  Searching by Phone number accessed by pressing ‘P’
5-  Searching by Date of birth accessed by pressing ‘D’
6-  Searching by Street address accessed by pressing ‘S’
7-  Searching by Multi search accessed by pressing ‘M’, the multi search was made to make it easy to search for multi aspects at the same time.
8-  Cancel the search and return to the menu accessed by pressing ‘C’


Sample run:
  
![image](https://user-images.githubusercontent.com/81472165/116831214-44b05c80-abae-11eb-824e-800862dec9fa.png)



	

# 2-Add contact

You can add new contacts to the list by using the add function by pressing ‘A’.
When you start adding the program will ask you to write:
1-	First name
2-	Last name
3-	The birth date day
4-	The birth date month
5-	The birth date year
6-	The Address
7-	The email
8-	The area code
9-	The phone number

![image](https://user-images.githubusercontent.com/81472165/116831226-4ed25b00-abae-11eb-8ece-79820c33c1fb.png)


After writing all the information the contact will be added to your list.

![image](https://user-images.githubusercontent.com/81472165/116831231-53970f00-abae-11eb-99d4-4cc5f5a65aad.png)

 


# 3-Delete contact

By pressing ‘D’ the delete function will let you search for any aspect in any contact you want and then prints all the contacts found with the contact number, then you can choose which contact you want to delete.
The function print the “Search to delete list” where you choose what to search just like the Search function as mentioned before.
Sample run :

![image](https://user-images.githubusercontent.com/81472165/116831237-5a258680-abae-11eb-8ac5-3820663fd422.png)


After the entering the data if you entered wrong data or no contact is found there is two options to choose, either search again by pressing ‘R’ or cancel search and return to menu by pressing ‘C’.

![image](https://user-images.githubusercontent.com/81472165/116831241-5f82d100-abae-11eb-9f23-5675486bc7a2.png)


# 4-Modify contact

The modify function starts by pressing ‘M’ button, the function then prints the search options list which is “Search to modify”  to help you find the contact you want to edit.

![image](https://user-images.githubusercontent.com/81472165/116831255-71647400-abae-11eb-8c6e-4e4c77a5163b.png)


After choosing any command the program will print all the found contacts and prints them allowing you to choose which contact you want , after choosing the contact a new list will be printed so you can choose what to edit in this contact.

Sample run :

![image](https://user-images.githubusercontent.com/81472165/116831259-76c1be80-abae-11eb-8ab4-e7108ebf1937.png)


After choosing a command from those given you will be asked for the new information you choose to change and then it will be done.
![image](https://user-images.githubusercontent.com/81472165/116831264-7cb79f80-abae-11eb-8b2f-5c20a7f5cd72.png)


# 5-Print sorted contacts
          
Can be accessed by pressing ‘P’.
This function is used to print all the contacts in your list according to three things 
		You can choose between:
		-First name
		-Last name
		-Birth date

![image](https://user-images.githubusercontent.com/81472165/116831270-84774400-abae-11eb-80cd-0a4e2df24fab.png)

After choosing a command from those given , the contacts in your list will be 
Printed after sorting.
		
		
Sample run:
 
 ![image](https://user-images.githubusercontent.com/81472165/116831277-8b05bb80-abae-11eb-8835-777b8d7b66d5.png)


# 6-Save

Don’t forget to save your progress by pressing ‘V’ or all your work will not be saved.
The save function is used to save all of the modifications done from all the previous
functions mentioned before.

Sample run:
![image](https://user-images.githubusercontent.com/81472165/116831285-90630600-abae-11eb-8522-ee86b6356ca6.png)



# 7-Quit

If you want to close the program you can just press ‘Q’, there will be three options to choose from:
		-yes 
		-no
		-yes, but save first 
             
Sample run :

![image](https://user-images.githubusercontent.com/81472165/116831288-96f17d80-abae-11eb-8044-c350088ac832.png)
	

These options are given because as we mentioned before your progress isn’t saved 
unless you save it by pressing ‘V’ else the changes you made is gone, so, if you  didn’t save the progress and choose to exit the program you have to choose between this options.
If “yes” is chosen the program will be closed and depending on you saving the progress or not it will not be saved.
If “no” is chosen you will return to the menu once again.
If “yes, but save first” is chosen then your work will be saved and the program will then close.

 
# Program algorithms

# Search algorithm :

The search algorithm is designed with the objective of generating a binary code that declares whether if each contact in the directory agrees to the search conditions declared by the user or not, this code of zeros and ones represents the applicability of each contact with the search specifications, with ‘1’ as true or applicable and ‘0’ as false or not applicable, the set of ones and zeros, that are position coded according to the number of the contact being checked, can then be used in any other operation, helping in filtering any data type according to acquired specifications.
An array of integers, declared as found with the size of existing contacts, is initially initialized and is passed to the main search algorithm in terms of a pointer pointing to the beginning of the array, giving the function free access to modify the array’s values.
The main search function also receives a character parameter that its value defines in which detail aspect the contact will be searched by, including a multi search option that will be discussed later on, this value is received from the user and checked for any invalidations.
The main applicability checking function is a function called substring, this function checks a string, that is supplied by the user as input, if whether it is actually a substring of the contact information being checked or not, returning the values of one or zero as a result of true or false, these values are to be put as the result of the found binary array.
The substring function works by comparing the first element of the given string with each element of the main string, if similarity attained, the second element of the given one is compared to the consecutive element of the main one and so on, until either similarity lost returning to comparing the first element of the given string, or the given string reaches an end and therefore the given string is in fact a substring of the main string and the value of one is to be returned, if the main string comes to an end before the given string, therefore the given string is not a substring and the value of zero is to be returned.
All elements are being reduced to lowercase (if not already) during comparison to overcome case sensitivity, also if the given string provided was empty “NULL” then it means no certain constrain is provided and all information are applicable, “NULL”  is a substring of everything.
For numerical data, the number is first copied into a string format, then that copy is checked for substring and the result is put as the value of the found binary array.
The Multi Search:
The multi search algorithm is an adaptation of the single search algorithm, as in the scope of the multi search function, a distinct sub-found array is being initialized for each detail aspect to be included in the search, the single search is done solely for each category resulting in a number of sub-found arrays with ‘0’ and ‘1’ values, again in the scope of the multi search function only.
This multi search function, like the main search function, receives a pointer pointing to the main found array to be modified, therefore for each contact number if all values of sub-found array is true, a value of one is to be put in the main found array declaring that indeed this contact is applicable to all search conditions specified.



# Sort algorithm :

The sort algorithm is mainly based on the concept of the bubble sorting, in which each two consecutive elements are to be checked as a pair for which should precede the other and if they are in an undesired order they are swapped together, this algorithm result in assuring that the value that belongs at the very end of the sequence will be placed there but does not assure that the rest of the elements are well sorted due to the variety of their original positions.
To maintain this problem the whole algorithm is repeated on the entire sequence except the last element as it’s assured to be in the rightful place. The repetition now also validate the position of the element before last, repeating the algorithm, with an interval of one element short than the previous one, till reaching a single element interval will assure the sorting of the whole sequence, the mixing of both algorithms is known as the concept of bubble sorting, the only difference in bubble sorting of one sequence than the other is the group of conditions that will determine whether swap should occur or not.
In this program, two main groups of conditions were used, one sorting by both first name and last name, and the other sorting the date of birth of the contact. The swapping condition for names was made by the strcasecmp function, if the name in the first element is bigger alphabetically than the name in the second element, ignoring uppercasing, the contacts are swapped, if the names are identical, the other name category is checked by the same way, accordingly sorting by first and last names and vice versa.
When it came to sorting by date, a group of different conditions where used to sort the contacts, that meant starting with the year first, if the first year is smaller than the second, then the person is older, then swap contacts, but then if the years were identical, the month is being checked the same way, swapping if the month is smaller, same with the similarity of months, then days are to be compared the same way. Another main point is that the occurrence of swap means that the condition was true, therefore checking the other conditions will not be valid as the previous one already satisfied, so a (continue;) function was used to escape any further useless comparisons.












Muhhamed Sallam      Amr Salah      Adham Wael
