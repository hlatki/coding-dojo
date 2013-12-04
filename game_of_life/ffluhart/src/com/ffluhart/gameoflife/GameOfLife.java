package com.ffluhart.gameoflife;


public class GameOfLife
{

   /**
    * @param args
    */
   public static void main(String[] args)
   {
      new GameOfLife("c:\\gol.txt");
   }
   
   public GameOfLife(String inputFile)
   {
      Grid currentGen = new Grid(inputFile);
      Grid nextGen = null;
      boolean generationsMatch = false;
      int generation = 1;
      while(!generationsMatch)
      {
         nextGen = new Grid(currentGen);
         advanceGen(currentGen, nextGen);
         generationsMatch = currentGen.equals(nextGen);
         if(!generationsMatch)
         {
            System.out.println("\n\nGeneration " + (++generation) + ":\n" + nextGen.toString());
         }
         currentGen = nextGen;
      }
   }

   private static void advanceGen(Grid currentGen, Grid nextGen)
   {
      for(int r = 0; r < currentGen.getRows(); r++)
      {
         for(int c = 0; c < currentGen.getColumns(); c++)
         {
            int adjacentLife = currentGen.getAdjacentLife(r, c);
            switch(adjacentLife)
            {
               case 0:
               case 1:
                  // Die due to underpopulation
                  nextGen.setValue(r, c, 0);
                  break;
               case 2:
                  // The cell is unchanged
                  break;
               case 3:
                  // Live cell
                  nextGen.setValue(r, c, 1);
                  break;
               default:
                  // Anything higher than 3 dies out due to overpopulation
                  nextGen.setValue(r, c, 0);
                  break;
            }
         }
      }
   }

}
