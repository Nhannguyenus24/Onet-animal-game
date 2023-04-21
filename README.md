# Onet-animal-game
The Matching Game (commonly known as Pikachu Puzzle Game) includes a board of multiple cells, each of which
presents a figure. The player finds and matches a pair of cells that contain the same figure and connect each other
in some particular pattern. A legal match will make the two cells disappear. The game ends when all matching
pairs are found. Figure 1 shows some snapshots from the Pikachu Puzzle Game.
In this project, we will develop a simplified version of this Matching Game by remaking the game with characters
(instead of figures).
Figure 1: The Pikachu Puzzle Game 1
1google.com
1
II Project Description
II.1 Standard Features
This mode contains the essential steps to make the game playable.
1. Game starting: Initialize a board with the given size while satisfying the following conditions
• The total number of cells must be even.
• The number of distinct characters is specified in advance.
• For each character, determine an even number to define the number of occurrences for that character.
2. Any matching pair must satisfy the following conditions
• Characters on the two cells must be identical.
• When the cells disappear, their positions are replaced with blank spaces.
• The matching pattern must be one of the below motifs
– I Matching
Figure 2: I Matching
– L Matching
Figure 3: L Matching
2
– U Matching
Figure 4: U Matching
– Z Matching
Figure 5: Z Matching
3. Game finishing: check the following conditions
• Are there any cells left?
• Are there any valid pairs left?
II.2 Technical requirements
• There must be a structural design for the board and player account.
• Game board content must be represented as a 2D-Pointer array.
• Save game must be stored as a binary file, which includes: player info, records, save stages, and other info.
3
II.3 Advanced Features
Players will experience the game better if you can add one (or more) of the following extra features to the game.
• Color and sound effects
• Visual effects 
Figure 6: Visual Effect
• Background: You can design anything for a background. Then, when a matching pair disappears, the background content corresponds to those emptied cells.
Figure 7: Game with background 2
• Leaderboard: The top N players that finished their games in the shortest time will register their information
to the Leaderboard.
• Move suggestion: Show players a valid match when they press the "Help" key.
• Game account and saved stages for each account
