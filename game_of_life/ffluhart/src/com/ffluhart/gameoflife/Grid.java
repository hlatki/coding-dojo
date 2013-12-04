package com.ffluhart.gameoflife;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;

public class Grid
{
   private int[][] _values;
   private int _rows;
   private int _columns;
   
   public Grid(String fileName)
   {
      BufferedReader br = null;
      try
      {
         br = new BufferedReader(new FileReader(fileName));
         String line = br.readLine();
         
         // The first line indicates the size of the grid
         String[] parts = line.split(" ");
         _rows = Integer.parseInt(parts[0]);
         _columns = Integer.parseInt(parts[1]);
         
         _values = new int[_rows][_columns];
         
         line = br.readLine();
         int r = 0;
         while(line != null && r < _rows)
         {
            // For each * in the line, set the associated grid point to 1
            for(int c = 0; c < line.length() && c < _columns; c++)
            {
               if(line.charAt(c) == '*')
               {
                  _values[r][c] = 1;
               }
            }
            line = br.readLine();
            r++;
         }
      }
      catch(Throwable e)
      {
         e.printStackTrace();
      }
      finally
      {
         if(br != null)
         {
            try
            {
               br.close();
            }
            catch(IOException e)
            {
               // Swallow this
            }
         }
      }
   }
   
   public Grid(Grid g)
   {
      _values = g.copy();
      _rows = g.getRows();
      _columns = g.getColumns();
   }
   
   public int[][] copy()
   {
      int[][] newGrid = new int[getRows()][getColumns()];
      for(int r = 0; r < getRows(); r++)
      {
         System.arraycopy(_values[r], 0, newGrid[r], 0, getColumns());
      }
      
      return newGrid;
   }
   
   public boolean equals(Grid g)
   {
      if(g == null)
      {
         return false;
      }
      
      if(getRows() != g.getRows() || getColumns() != g.getColumns())
      {
         return false;
      }
      
      for(int r = 0; r < getRows(); r++)
      {
         if(!Arrays.equals(_values[r], g.getValues()[r]))
         {
            return false;
         }
      }
      
      return true;
   }
   
   public int getAdjacentLife(int row, int column)
   {
      int life = 0;
      
      for(int r = Math.max(0, row - 1); r <= Math.min(getRows() - 1, row + 1); r++)
      {
         for(int c = Math.max(0, column - 1); c <= Math.min(getColumns() - 1, column + 1); c++)
         {
            if(!(r == row && c == column))
            {
               life += _values[r][c];
            }
         }
      }
      
      return life;
   }
   
   public void setValue(int row, int column, int value)
   {
      _values[row][column] = value;
   }
   
   public String toString()
   {
      StringBuffer result = new StringBuffer();
      for(int r = 0; r < getRows(); r++)
      {
         if(r > 0)
         {
            result.append("\n");
         }
         
         for(int c = 0; c < getColumns(); c++)
         {
            result.append(_values[r][c] == 0 ? "." : "*");
         }
      }
      
      return result.toString();
   }

   public int getRows()
   {
      return _rows;
   }

   public void setRows(int rows)
   {
      _rows = rows;
   }

   public int getColumns()
   {
      return _columns;
   }

   public void setColumns(int columns)
   {
      _columns = columns;
   }

   public int[][] getValues()
   {
      return _values;
   }
}
