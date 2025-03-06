Stack & Move
#stackgame

Stack Game is a logic-based game where players must organize numbers in stacks according to specific rules. The goal is to arrange all stacks such that each stack contains only identical numbers.

"RULES:"
1. THE ELEMENTS ARE PUT INTO THREE STACKS IN RANDOM ORDER.
2. YOU ARE GIVEN AN EXTRA EMPTY STACK.
3. YOU CAN PUSH AN ELEMENT INTO THE STACK ONLY IF SIZE OF THE STACK IS LESS THAN 3 AND THE TOP ELEMENT EQUALS THE ELEMENT WHICH YOU WOULD BE PUSHING IN.
4. YOUR WORK IS TO USE ALL STACKS AND CREATE A WINNING SCENARIO SUCH THAT ALL NUMBERS IN A STACK ARE EQUAL.
5. TRY TO GET IT DONE IN MINIMUM NUMBER OF MOVES AS EVERY WRONG MOVE COUNTS.
6. MAKE THE MOVE CONTAINS TAKES INPUT OF TWO INTEGERS:
7. INTEGER 1: THE STACK YOU ARE CHOOSING TO MOVE THE ELEMENT FROM.
8. INTEGER 2: THE STACK YOU ARE CHOOSING TO MOVE THE ELEMENT IN.
9. CODES: '1' FOR STACK 1, '2' FOR STACK 2, '3' FOR STACK 3, '4' FOR STACK 4.
10. TYPE 'YES' IF YOU WANT TO MOVE ON TO THE NEXT LEVEL. ELSE TYPE 'NO'.
11. TRY TO PLAY CAUTIOUSLY BECAUSE IF YOU ARRIVE AT AN UNPLAYABLE SITUATION, YOU MIGHT HAVE TO START ALL OVER AGAIN BY REFRESHING YOUR TERMINAL.

Installation:

To run the game on your system:
# Clone the repository
git clone https://github.com/ayushks27/stackgame.git
cd stackgame

# Compile the C++ program
g++ stackgame.cpp -o stackgame

# Run the game
./stackgame

Contributing

Contributions are welcome! Feel free to submit a pull request with improvements.

License

This project is licensed under the MIT License.

Enjoy playing the Stack Game and challenge yourself to master the logic behind the stacks!
