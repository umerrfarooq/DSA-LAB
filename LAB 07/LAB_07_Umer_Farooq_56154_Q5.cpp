#include <iostream>
#include <string>
using namespace std;

class Song {
public:
    string title;
    Song* next;
    Song* prev;

    Song(string songTitle) {
        title = songTitle;
        next = NULL;
        prev = NULL;
    }
};

class Playlist {
private:
    Song* head;

public:
    Playlist() {
        head = NULL;
    }

    // Add a new song to the end of the playlist
    void addSong(string songTitle) {
        Song* newSong = new Song(songTitle);
        if (head == NULL) {
            head = newSong;
        } else {
            Song* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newSong;
            newSong->prev = temp;
        }
        cout << "Added: " << songTitle << " to the playlist.\n";
    }

    // Display the playlist from the start (forwards)
    void displayPlaylist() {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        Song* temp = head;
        cout << "Playlist (Forwards):\n";
        while (temp != NULL) {
            cout << temp->title << " -> ";
            temp = temp->next;
        }
        cout << "END\n";
    }

    // Display the playlist from the end (backwards)
    void displayReversePlaylist() {
        if (head == NULL) {
            cout << "Playlist is empty.\n";
            return;
        }

        // Traverse to the last song
        Song* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        cout << "Playlist (Backwards):\n";
        while (temp != NULL) {
            cout << temp->title << " -> ";
            temp = temp->prev;
        }
        cout << "START\n";
    }

    // Delete a song by its title
    void deleteSong(string songTitle) {
        if (head == NULL) {
            cout << "Playlist is empty. Cannot delete.\n";
            return;
        }

        // If the song to be deleted is the first song
        if (head->title == songTitle) {
            Song* toDelete = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete toDelete;
            cout << "Deleted: " << songTitle << " from the playlist.\n";
            return;
        }

        // Traverse the list to find the song
        Song* temp = head;
        while (temp != NULL && temp->title != songTitle) {
            temp = temp->next;
        }

        // If the song is not found
        if (temp == NULL) {
            cout << "Song not found in the playlist.\n";
            return;
        }

        // Remove the song from the playlist
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Deleted: " << songTitle << " from the playlist.\n";
    }
};

int main() {
    Playlist myPlaylist;

    // Adding songs
    myPlaylist.addSong("Song A");
    myPlaylist.addSong("Song B");
    myPlaylist.addSong("Song C");

    // Displaying playlist forwards
    myPlaylist.displayPlaylist();

    // Displaying playlist backwards
    myPlaylist.displayReversePlaylist();

    // Deleting a song
    myPlaylist.deleteSong("Song B");
    myPlaylist.displayPlaylist();

    return 0;
}
