#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Movie {
public:
    int movie_id;
    string title;
    int available_seats;
    Movie(int id, string t, int seats) {
        movie_id = id;
        title = t;
        available_seats = seats;
    }
    void display() const {
        cout << "Movie: " << title << " | ID: " << movie_id << " | Seats: " << available_seats << endl;
    }
    bool book_seat() {
        if (available_seats > 0) {
            available_seats--;
            return true;
        }
        return false;
    }
};
class Booking {
public:
    string customer_name;
    string movie_title;
    Booking(string name, string title) {
        customer_name = name;
        movie_title = title;
    }
    void display() const {
        cout << "Customer: " << customer_name << " | Movie: " << movie_title << endl;
    }
};
class Cinema {
private:
    vector<Movie> movies;
    vector<Booking> bookings;
public:
    void add_movie(int id, string title, int seats) {
        movies.emplace_back(id, title, seats);
        cout << "Movie " << title << " added.\n";
    }
    void book_ticket(string customer, int movie_id) {
        for (Movie& m : movies) {
            if (m.movie_id == movie_id) {
                if (m.book_seat()) {
                    bookings.emplace_back(customer, m.title);
                    cout << "Ticket booked for " << customer << endl;
                } else {
                    cout << "No seats available.\n";
                }
                return;
            }
        }
        cout << "Movie not found.\n";
    }
    void view_movies() const {
        for (const Movie& m : movies)
            m.display();
    }
    void view_bookings() const {
        for (const Booking& b : bookings)
            b.display();
    }
};