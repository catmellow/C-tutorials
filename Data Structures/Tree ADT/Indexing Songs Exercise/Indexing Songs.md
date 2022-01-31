# Indexing Songs

This exercise will help you to practice the AVL Tree ADT. Write a program that can analyze songs available in the given playlist. The application indexes the songs and finds the pieces belonging to the most famous artist and genre in a given song playlist.

#### **Requirements:**
In this exercise, you are given a text file called “songs.txt” that includes the data about the songs in the playlist. This file contains the following information:

* **Song Name:** This is the name of the song.
* **Song Genre:** This is the genre of the song.
* **Album Name:** This is the name of the album that the song belongs.
* **Artist Name:** This is the name of the artist that the song belongs.
* **Release Year:** It shows the year that the song is released.
* **Date:** It shows the date and time of the song that is added to your playlist.

sample data is as follows where each part is separated by a ";" character:

```
Unutmamali;Pop;Aacayipsin;Tarkan;1994;22/10/2019 14:11
Huzurum Kalmadi;Arabesque;Huzurum Kalmadi;Ferdi Tayfur;1976;22/12/2018 15:15
Sorma Kalbim;Pop;Dudu;Tarkan;2003;3/6/2005 15:12
Gemiler;Rock;O;Teoman;1998; 15/4/2002 08:30
```

The task is to process this file and generate an AVL tree based on the artist name data. If there is more than one post with the same artist name, they should be stored together in the same node. Based on this data representation, the program should provide the following functionalities to the user:

1. **Display the complete index:** This will display the full AVL tree constructed. It would be best to show the songs alphabetically sorted based on their artist name for traversal.
2. **The artist with the maximum number of songs:** This will display the details (Song Name, Song Genre, Album Name, Artist Name, Release Year, and Date) of the artist's songs who has the maximum number of songs.
3. **The oldest song:** This will display the details (Song Name, Song Genre, Album Name, Artist Name, Release Year, and Date) of the oldest music (the song has the minimum year, etc.)

#### **Programming Requirements:**

Starting by taking the file name as a command-line argument and then continuing to implement at least the following functions:






| **Function** | **Description** | 
| -------- | -------- | 
| **readData**     | This function will mainly process the external file. As an input, it will take the file name and return an AVL tree.     | 
| **insertSong**     | This function will take an AVL tree and the details of a song, and then it will insert the song to the AVL tree. The song will be interested in the tree based on the artist's name. You cannot make assumptions about the number of songs that belong to the same artist name. Therefore, if the node with the given artist name exists, you will add your song details to that node.     | 
| **displaySongs**     | This function will mainly take an AVL tree and display the data in the tree in alphabetical order according to the artist's name.     | 
| **popularArtist**     | This function will take an AVL tree as a parameter to find and display the details of the songs of the artist name, which has the maximum number of songs. In the comment part of this function, discuss the complexity based on your current representation of data. You also need to examine if there is a way you could improve this.     | 
| **oldestSong**     | This function will take an AVL tree as a parameter will find and display the details of the oldest song (song with minimum Release Year). In the comment part of this function, discuss the complexity based on your current representation of data. You also need to examine if there is a way you could improve this.     | 


> Please note that you can use the functions in the string in this assignment.h library and similar external libraries. You cannot assume the number of songs in this external file.

You can find the sample run of the program as follows

#### ***Sample Run***



```
Welcome to Song Indexing 
-----------------------------------------------------------------------------

1. Display the full index of songs
2. Display the songs of popular artist
3. Display the oldest song
4. Exit

Option: 1

Huzurum Kalmadi;Arabesque;Huzurum Kalmadi;Ferdi Tayfur;1976;22/12/2018 15:15
Unutmamali;Pop;Aacayipsin;Tarkan;1994;22/10/2019 14:11
Sorma Kalbim;Pop;Dudu;Tarkan;2003;3/6/2005 15:12
Gemiler;Rock;O;Teoman;1998; 15/4/2002 08:30

-----------------------------------------------------------------------------
1. Display the full index of songs
2. Display the songs of popular artist
3. Display the oldest song
4. Exit

Option: 2

Unutmamali;Pop;Aacayipsin;Tarkan;1994;22/10/2019 14:11
Sorma Kalbim;Pop;Dudu;Tarkan;2003;3/6/2005 15:12

-----------------------------------------------------------------------------
1. Display the full index of songs
2. Display the songs of popular artist
3. Display the oldest song
4. Exit

Option: 3
Huzurum Kalmadi;Arabesque;Huzurum Kalmadi;Ferdi Tayfur;1976;22/12/2018 15:15
-----------------------------------------------------------------------------
1. Display the full index of songs
2. Display the songs of popular artist
3. Display the oldest song
4. Exit
Option: 4

```
