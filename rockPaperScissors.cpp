// Copyright (c) 2025 Luke Di Bert
// Created by: Luke Di Bert
// Date: May 2, 2025

// libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

int main() {
    // arrays holding options and game outcome
    const std::string interactions[] = {"lose!", "tied!", "win!"};
    const int rock[] = {1, 0, 2};
    const int paper[] = {2, 1, 0};
    const int scissors[] = {0, 2, 1};

    // Variables for wins and losses
    int wins = 0;
    int losses = 0;

    // random seed using time
    srand(time(0));

    // Loop the game
    while (true) {
        std::string input;
        int user_choice;

        // asks user to choose move
        std::cout << "Choose rock(0), paper(1), or scissors(2): ";
        std::cin >> input;

        // try catch for the move input section
        try {
            // converts input into int
            user_choice = std::stoi(input);

            // checks if user num is in range
            if (user_choice >= 0 && user_choice <= 2) {
                // random computer move
                int comp_choice = rand() % 2 + 1;

                // Computer's choice
                if (comp_choice == 0)
                    std::cout << "Opponent chose rock\n";
                else if (comp_choice == 1)
                    std::cout << "Opponent chose paper\n";
                else
                    std::cout << "Opponent chose scissors\n";

                // Player's choice and outcome
                if (user_choice == 0) {
                    std::cout << "You chose rock\n";
                    std::cout << "You "
                              << interactions[rock[comp_choice]] << "\n";
                    if (rock[comp_choice] == 2) wins++;
                    if (rock[comp_choice] == 0) losses++;
                } else if (user_choice == 1) {
                    std::cout << "You chose paper\n";
                    std::cout << "You "
                              << interactions[paper[comp_choice]] << "\n";
                    if (paper[comp_choice] == 2) wins++;
                    if (paper[comp_choice] == 0) losses++;
                } else if (user_choice == 2) {
                    std::cout << "You chose scissors\n";
                    std::cout << "You "
                              << interactions[scissors[comp_choice]] << "\n";
                    if (scissors[comp_choice] == 2) wins++;
                    if (scissors[comp_choice] == 0) losses++;
                }
            } else {
                // displays if num was not in range
                std::cout << user_choice << " was not in the range 0-2!\n";
            }

            // Ask if player wants to continue
            std::string quit_input;
            int user_quit;
            std::cout << "Play another round? yes(1), no(0): ";
            std::cin >> quit_input;

            // try for quit_input
            try {
                // converts to integer
                user_quit = std::stoi(quit_input);
                if (user_quit == 0) {
                    std::cout << "Thanks for playing!\n";

                    // displays wins and losses
                    std::cout << "You won " << wins
                              << " times, and lost " << losses << " times!\n";
                    break;
                } else if (user_quit != 1) {
                    // displays if num not in range
                    std::cout << user_quit
                              << " was not in the range 0-1!\n";
                }

            // catches invalid integer
            } catch (const std::invalid_argument&) {
                std::cout << quit_input << " was not a valid integer!\n";
            }

        // catches invalid integer
        } catch (const std::invalid_argument&) {
            std::cout << input << " was not a valid integer!\n";
        }
    }
}
