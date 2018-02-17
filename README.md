# Turn-Based-RPG-Genetic-Algorithm
My own genetic algorithm implementation designed for a turn-based RPG to evolve an enemy's strategy based on the player's party member character's stats.

The genetic algorithm I have designed aimed to create a enemy (potentially a boss enemy) that contiously evolved it's strategy according
to the player characters' stats. This would then provide the player with an enemy to face that is a lot more challenging since no matter
what the player's stats are the enemy will eventually find the player characters' weaknesses.

The genetic algorithm is designed to make gameplay more interesting. I did a simple theortical experiment to compare the performance of my
genetic algorithm compared to a a hand crafted algorithm (that knows the player's weakness already and always exploits that weakness), as
well as against a random AI. For the experiment I measured how quickly it would take an enemy to defeat a player (without reply from the
player and without considerations of healing). The GA over 100 iterations performed as good as the hand crafted AI and as expected
performed better than a random AI. I believe this is a reason why a GA like this is good for gamplay because the genetic algorithm would
take time to come up with an effective strategy against the player, so this gives the player a fair chance and also provides enough
difficulty as the GA starts to work out an effective startegy. A hand crafted AI would be very tough from the start, whereas a random AI
would provide the player with less of a challenge.

My genetic algorithm follows this general pattern:
  Selection of moves for population - selects 4 attack out of the availiable attacks sets
  Fitness calculation - calculates the fitness (amount of damage that would be done to a player if executed) for each attacks selected
  Roulette wheel selection - 1 attack is executed out of the four attacks selected, with the probablity of the attack being selected     
      proportional to the fitness.
    -attack selected is used in the selection process next iteration
  Mutation - used to add vartion to the moves executed - if an attack has been executed 3 out of the last 5 executed attacks, then it won't
      be selected in the selection process.
