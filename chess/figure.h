#include <math.h>
#include <cctype>
//pijuni
void pijuni(int row_to, int row_from, char column_to, char column_from, char board[][8], char bijeli_jede[][8], char crni_jede[][8], int &ilegalno) {
    int column_to_int = 0, column_from_int = 0;
	column_to_int = char_to_int(column_to);
	column_from_int = char_to_int(column_from);



	// crni pijuni
  if(board[row_from][column_from_int] == 'p')
  {
    if (row_from == 6 && row_to > 3 && column_from == column_to && board[row_to][(char_to_int(column_to))] == ' ' && board[5][(char_to_int(column_to))] == ' ') 
    {
      logika_za_crtanje(row_to, row_from, column_to, column_from, board);
    } 
    else if (row_from != 6 && column_from == column_to && board[row_to][(char_to_int(column_to))] == ' ') 
    {
      if (row_from == row_to + 1)
        logika_za_crtanje(row_to, row_from, column_to, column_from, board);
      else
        ilegalno = 1;
    } 
    else
      ilegalno = 1;
    //jedenje crni jede 
    if((row_from-row_to==1) && abs(column_to-column_from)==1)
    {
      if(isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='k')
      {
        for( int i = 0; i<2; i++)
        {
          for(int j=0; j<8; j++) 
          {
            if(crni_jede[i][j] == ' ') 
            {
              crni_jede[i][j] = board[row_to][column_to_int];
              board[row_to][column_to_int] = ' ';
            }
          }
        }
        logika_za_crtanje(row_to, row_from, column_to, column_from, board);
        ilegalno = 0;
      }
    }
  }
	// bijeli pijuni
  if(board[row_from][column_from_int] == 'P')
  {
    if (row_from == 1 && row_to < 4 && column_from == column_to &&
			board[row_to][(char_to_int(column_to))] == ' ' && board[2][(char_to_int(column_to))] == ' ') 
    {
      logika_za_crtanje(row_to, row_from, column_to, column_from, board);
    } 
    else if (row_from != 1 && column_from == column_to &&
			board[row_to][(char_to_int(column_to))] == ' ') 
    {
      if (row_from == row_to - 1)
        logika_za_crtanje(row_to, row_from, column_to, column_from, board);
      else
        ilegalno = 1;
    } 
    else
      ilegalno = 1;
    //bjeli jede 
    if((row_from-row_to==-1) && abs(column_to-column_from)==1)
    {
      if(islower(board[row_to][column_to_int]) > 0 && isupper(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
      {
        for( int i = 0; i<2; i++)
        {
          for(int j=0; j<8; j++) 
          {
            if(bijeli_jede[i][j] == ' ') 
            {
              bijeli_jede[i][j] = board[row_to][column_to_int];
              board[row_to][column_to_int] = ' ';
            }
          }
        }
        logika_za_crtanje(row_to, row_from, column_to, column_from, board);
        ilegalno = 0;
      }
    }
  }
}
//kula
void kula(int row_to, int row_from, char column_to, char column_from, char board[][8], char bijeli_jede[][8], char crni_jede[][8], int &ilegalno)
{
  int column_to_int = 0, column_from_int = 0;
	column_to_int = char_to_int(column_to);
	column_from_int = char_to_int(column_from);
  int moze = 1;
  
    if(column_to_int == column_from_int && row_to != row_from) 
    {
      if(row_from - row_to > 0) //Gore
      {
        for(int i = row_from-1; i>=row_to; i--)
        {
          if(board[i][column_to_int] != ' ') 
          {
            if(i==row_to)
            {
              if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
              {
                for( int i = 0; i<2; i++)
                {
                  for(int j=0; j<8; j++) 
                  {
                    if(crni_jede[i][j] == ' ') 
                    {
                      crni_jede[i][j] = board[row_to][column_to_int];
                      board[row_to][column_to_int] = ' ';
                    }
                  }
                }
              }
              if (islower(board[row_to][column_to_int]) > 0 && isupper(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='k')
              {
                for( int i = 0; i<2; i++)
                {
                  for(int j=0; j<8; j++) 
                  {
                    if(bijeli_jede[i][j] == ' ') 
                    {
                      bijeli_jede[i][j] = board[row_to][column_to_int];
                      board[row_to][column_to_int] = ' ';
                    }
                  }
                }
              }
            }
            else 
            moze=0;
          }
        }
      }
      else if(row_from - row_to < 0) //Dolje
      {
        for(int i = row_from+1; i<=row_to; i++)
        {
          if(board[i][column_to_int] != ' ') 
          {
            if(i==row_to)
            {
              if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
              {
                for( int i = 0; i<2; i++)
                {
                  for(int j=0; j<8; j++) 
                  {
                    if(crni_jede[i][j] == ' ') 
                    {
                      crni_jede[i][j] = board[row_to][column_to_int];
                      board[row_to][column_to_int] = ' ';
                    }
                  }
                }
              }
              if (islower(board[row_to][column_to_int]) > 0 && isupper(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='k')
              {
                for( int i = 0; i<2; i++)
                {
                  for(int j=0; j<8; j++) 
                  {
                    if(bijeli_jede[i][j] == ' ') 
                    {
                      bijeli_jede[i][j] = board[row_to][column_to_int];
                      board[row_to][column_to_int] = ' ';
                    }
                  }
                }
              }
            }
            else 
            moze=0;
          }
        }
      }

    }
    else if(column_to_int != column_from_int && row_to == row_from) 
    {
      if(column_from_int - column_to_int > 0) //Lijevo
      {
        for(int i = column_from_int-1; i>=column_to_int; i--)
        {
          if(board[row_to][i] != ' ') 
          {
           if(i==column_to_int)
            {
              if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
              {
                for( int i = 0; i<2; i++)
                {
                  for(int j=0; j<8; j++) 
                  {
                    if(crni_jede[i][j] == ' ') 
                    {
                      crni_jede[i][j] = board[row_to][column_to_int];
                      board[row_to][column_to_int] = ' ';
                    }
                  }
                }
              }
              if (islower(board[row_to][column_to_int]) > 0 && isupper(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='k')
              {
                for( int i = 0; i<2; i++)
                {
                  for(int j=0; j<8; j++) 
                  {
                    if(bijeli_jede[i][j] == ' ') 
                    {
                      bijeli_jede[i][j] = board[row_to][column_to_int];
                      board[row_to][column_to_int] = ' ';
                    }
                  }
                }
              }
            }
            else 
            moze=0;
          }
        }
      }
      else if(column_from_int - column_to_int < 0) //Desno
      {
        for(int i = column_from_int+1; i<=column_to_int; i++)
        {
          if(board[row_to][i] != ' ') 
          {
            if(i==column_to_int)
            {
              if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
              {
                for( int i = 0; i<2; i++)
                {
                  for(int j=0; j<8; j++) 
                  {
                    if(crni_jede[i][j] == ' ') 
                    {
                      crni_jede[i][j] = board[row_to][column_to_int];
                      board[row_to][column_to_int] = ' ';
                    }
                  }
                }
              }
              if (islower(board[row_to][column_to_int]) > 0 && isupper(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='k')
              {
                for( int i = 0; i<2; i++)
                {
                  for(int j=0; j<8; j++) 
                  {
                    if(bijeli_jede[i][j] == ' ') 
                    {
                      bijeli_jede[i][j] = board[row_to][column_to_int];
                      board[row_to][column_to_int] = ' ';
                    }
                  }
                }
              }
            }
            else 
            moze=0;
          }
        }
      }
      
    }
    else
    {
      moze=0;
      ilegalno=1;
    }
  if(moze == 1) 
  {
    if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0)
    {
      for( int i = 0; i<2; i++)
      {
        for(int j=0; j<8; j++) 
        {
          if(crni_jede[i][j] == ' ') 
          {
            crni_jede[i][j] = board[row_to][column_to_int];
            board[row_to][column_to_int] = ' ';
          }
        }
      }
    }
    logika_za_crtanje(row_to, row_from, column_to, column_from, board);
  }
  else
  {
    moze = 1;
    ilegalno = 1;
  }
}

//konj
void konj(int row_to, int row_from, char column_to, char column_from, char board[][8], char bijeli_jede[][8], char crni_jede[][8], int &ilegalno)
{
  int column_to_int = 0, column_from_int = 0;
	column_to_int = char_to_int(column_to);
	column_from_int = char_to_int(column_from);

  //crni konj
  if(board[row_from][char_to_int(column_from)] == 'h')
  {
    if((abs(row_from-row_to)==2) && (abs(column_to-column_from)==1))
    {
        if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='k')
        { 
          for( int i = 0; i<2; i++)
          {
            for(int j=0; j<8; j++) 
            {
              if(crni_jede[i][j] == ' ') 
              {
                crni_jede[i][j] = board[row_to][column_to_int];
                board[row_to][column_to_int] = ' ';
              }
            }
          } 
        }
        else if(islower(board[row_to][column_to_int]) > 0) ilegalno = 1;
        if(ilegalno == 0) logika_za_crtanje(row_to, row_from, column_to, column_from, board);
    }
    else if(abs(column_from-column_to)==2 && abs(row_from-row_to)==1)
    {
      if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='k')
      { 
        for( int i = 0; i<2; i++)
        {
          for(int j=0; j<8; j++) 
          {
            if(crni_jede[i][j] == ' ') 
            {
              crni_jede[i][j] = board[row_to][column_to_int];
              board[row_to][column_to_int] = ' ';
            }
          }
        } 
      }
      else if(islower(board[row_to][column_to_int]) > 0) ilegalno = 1;
      if(ilegalno == 0) logika_za_crtanje(row_to, row_from, column_to, column_from, board);
    }  
    else 
    ilegalno=1;
  }
    //bijeli konj
    if(board[row_from][char_to_int(column_from)] == 'H')
    {
      if((abs(row_from-row_to)==2) && (abs(column_to-column_from)==1))
      {
        if (islower(board[row_to][column_to_int]) > 0 && isupper(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
        {
          for( int i = 0; i<2; i++)
          {
            for(int j=0; j<8; j++) 
            {
              if(bijeli_jede[i][j] == ' ') 
              {
                bijeli_jede[i][j] = board[row_to][column_to_int];
                board[row_to][column_to_int] = ' ';
              }
            }
          }
        }
        else if(islower(board[row_to][column_to_int]) > 0) ilegalno = 1;
        if(ilegalno == 0) logika_za_crtanje(row_to, row_from, column_to, column_from, board);
      }
    else if(abs(column_from-column_to)==2 && abs(row_from-row_to)==1)
    {
      if(board[row_to][column_to_int]==' ')
      {
        if (islower(board[row_to][column_to_int]) > 0 && isupper(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
        {
          for( int i = 0; i<2; i++)
          {
            for(int j=0; j<8; j++) 
            {
              if(bijeli_jede[i][j] == ' ') 
              {
                bijeli_jede[i][j] = board[row_to][column_to_int];
                board[row_to][column_to_int] = ' ';
              }
            }
          }
        }
        else if(islower(board[row_to][column_to_int]) > 0) ilegalno = 1;
        if(ilegalno == 0) logika_za_crtanje(row_to, row_from, column_to, column_from, board);
      }
    }
    else 
    ilegalno=1;
  }

}

//lovac
void lovac(int row_to, int row_from, char column_to, char column_from, char board[][8], char bijeli_jede[][8], char crni_jede[][8], int &ilegalno)
{
  int column_to_int = 0, column_from_int = 0;
	column_to_int = char_to_int(column_to);
	column_from_int = char_to_int(column_from);
  int moze=1;

  //lovac u kraljici
  //Crni jede
  if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
  { 
    for( int i = 0; i<2; i++)
    {
      for(int j=0; j<8; j++) 
      {
        if(crni_jede[i][j] == ' ') 
        {
          crni_jede[i][j] = board[row_to][column_to_int];
          board[row_to][column_to_int] = ' ';
        }
      }
    } 
  }
  //Bijeli jede
  if (islower(board[row_to][column_to_int]) > 0 && isupper(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
  { 
    for( int i = 0; i<2; i++)
    {
      for(int j=0; j<8; j++) 
      {
        if(bijeli_jede[i][j] == ' ') 
        {
          bijeli_jede[i][j] = board[row_to][column_to_int];
          board[row_to][column_to_int] = ' ';
        }
      }
    } 
  }
  if(abs(row_from-row_to)==abs(column_from-column_to))
  {
    for(int i=row_from;i!=row_to;)
    {
      for(int j=column_from_int;j!=column_to_int;)
      {
        if(abs(i-j)==abs(row_from-column_from_int))
        {
          if(row_from>row_to)
            i--;
          else
            i++;
          if(column_from_int>column_to_int)
            j--;
          else
            j++;
          if(board[i][j]!=' ')
            moze=0;
        }
        else
        {
          if(row_from>row_to)
            i--;
          else
            i++;
          if(column_from_int>column_to_int)
            j--;
          else
            j++;
        }     
      }
    }
    if(moze==1)
      logika_za_crtanje(row_to, row_from, column_to, column_from, board);
    else
      ilegalno=1;
  }
}

//kralj
void kralj(int row_to, int row_from, char column_to, char column_from, char board[][8], char bijeli_jede[][8], char crni_jede[][8], int &ilegalno)
{
  int column_to_int = 0, column_from_int = 0;
	column_to_int = char_to_int(column_to);
	column_from_int = char_to_int(column_from);
  int moze=1;

  if(board[row_from][char_to_int(column_from)] == 'k' || board[row_from][char_to_int(column_from)] == 'K')
  {
    if(abs(row_from-row_to)<2 && abs(column_from-column_to)<2)
    {
      if(board[row_to][column_to_int]!=' ')
        moze=0;
      if(board[row_from][column_from_int]=='k')
      {
        if(board[row_to+1][column_to_int]=='K')
          moze=0;
        if(board[row_to+1][column_to_int+1]=='K')
          moze=0;
        if(board[row_to+1][column_to_int-1]=='K')
          moze=0;
        if(board[row_to][column_to_int+1]=='K')
          moze=0;
        if(board[row_to-1][column_to_int+1]=='K')
          moze=0;
        if(board[row_to-1][column_to_int-1]=='K')
          moze=0;
        if(board[row_to-1][column_to_int]=='K')
          moze=0;
        if(board[row_to][column_to_int-1]=='K')
          moze=0;
      }
      if(board[row_from][column_from_int]=='K')
      {
        if(board[row_to+1][column_to_int]=='k')
          moze=0;
        if(board[row_to+1][column_to_int+1]=='k')
          moze=0;
        if(board[row_to+1][column_to_int-1]=='k')
          moze=0;
        if(board[row_to][column_to_int+1]=='k')
          moze=0;
        if(board[row_to-1][column_to_int+1]=='k')
          moze=0;
        if(board[row_to-1][column_to_int-1]=='k')
          moze=0;
        if(board[row_to-1][column_to_int]=='k')
          moze=0;
        if(board[row_to][column_to_int-1]=='k')
          moze=0;
      }
      if(moze==1)
        logika_za_crtanje(row_to, row_from, column_to, column_from, board);
      else
        ilegalno=1;
    }
    else
      ilegalno=1;
  }
}

//kraljica
void kraljica(int row_to, int row_from, char column_to, char column_from, char board[][8], char bijeli_jede[][8], char crni_jede[][8], int &ilegalno)
{
  int column_to_int = 0, column_from_int = 0;
  column_to_int = char_to_int(column_to);
	column_from_int = char_to_int(column_from);
  int moze=1;
//lovac u kraljici
  //Crni jede
  if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
  { 
    for( int i = 0; i<2; i++)
    {
      for(int j=0; j<8; j++) 
      {
        if(crni_jede[i][j] == ' ') 
        {
          crni_jede[i][j] = board[row_to][column_to_int];
          board[row_to][column_to_int] = ' ';
        }
      }
    } 
  }
  //Bijeli jede
  if (islower(board[row_to][column_to_int]) > 0 && isupper(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
  { 
    for( int i = 0; i<2; i++)
    {
      for(int j=0; j<8; j++) 
      {
        if(bijeli_jede[i][j] == ' ') 
        {
          bijeli_jede[i][j] = board[row_to][column_to_int];
          board[row_to][column_to_int] = ' ';
        }
      }
    } 
  }
  if(abs(row_from-row_to)==abs(column_from-column_to))
  {
    for(int i=row_from;i!=row_to;)
    {
      for(int j=column_from_int;j!=column_to_int;)
      {
        if(abs(i-j)==abs(row_from-column_from_int))
        {
          if(row_from>row_to)
            i--;
          else
            i++;
          if(column_from_int>column_to_int)
            j--;
          else
            j++;
          if(board[i][j]!=' ')
            moze=0;
        }
        else
        {
          if(row_from>row_to)
            i--;
          else
            i++;
          if(column_from_int>column_to_int)
            j--;
          else
            j++;
        }     
      }
    }
      logika_za_crtanje(row_to, row_from, column_to, column_from, board);
  }

//kula u kraljici
  if(column_to_int == column_from_int && row_to != row_from) 
  {
    if(row_from - row_to > 0) //Gore
    {
      for(int i = row_from-1; i>=row_to; i--)
      {
        if(board[i][column_to_int] != ' ') 
        {
          if(i==row_to)
          {
            if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
            {
              for( int i = 0; i<2; i++)
              {
                for(int j=0; j<8; j++) 
                {
                  if(crni_jede[i][j] == ' ') 
                  {
                    crni_jede[i][j] = board[row_to][column_to_int];
                    board[row_to][column_to_int] = ' ';
                  }
                }
              }
            }
            if (islower(board[row_to][column_to_int]) > 0 && isupper(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='k')
            {
              for( int i = 0; i<2; i++)
              {
                for(int j=0; j<8; j++) 
                {
                  if(bijeli_jede[i][j] == ' ') 
                  {
                    bijeli_jede[i][j] = board[row_to][column_to_int];
                    board[row_to][column_to_int] = ' ';
                  }
                }
              }
            }
          }
          else 
          moze=0;
        }
      }
    }
    else if(row_from - row_to < 0) //Dolje
    {
      for(int i = row_from+1; i<=row_to; i++)
      {
        if(board[i][column_to_int] != ' ') 
        {
          if(i==row_to)
          {
            if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
            {
              for( int i = 0; i<2; i++)
              {
                for(int j=0; j<8; j++) 
                {
                  if(crni_jede[i][j] == ' ') 
                  {
                    crni_jede[i][j] = board[row_to][column_to_int];
                    board[row_to][column_to_int] = ' ';
                  }
                }
              }
            }
            if (islower(board[row_to][column_to_int]) > 0 && isupper(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='k')
            {
              for( int i = 0; i<2; i++)
              {
                for(int j=0; j<8; j++) 
                {
                  if(bijeli_jede[i][j] == ' ') 
                  {
                    bijeli_jede[i][j] = board[row_to][column_to_int];
                    board[row_to][column_to_int] = ' ';
                  }
                }
              }
            }
          }
          else 
            moze=0;
        }
      }
    }
    }
    else if(column_to_int != column_from_int && row_to == row_from) 
    {
      if(column_from_int - column_to_int > 0) //Lijevo
      {
        for(int i = column_from_int-1; i>=column_to_int; i--)
        {
          if(board[row_to][i] != ' ') 
          {
          if(i==column_to_int)
            {
              if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
              {
                for( int i = 0; i<2; i++)
                {
                  for(int j=0; j<8; j++) 
                  {
                    if(crni_jede[i][j] == ' ') 

                    {
                      crni_jede[i][j] = board[row_to][column_to_int];
                      board[row_to][column_to_int] = ' ';
                    }
                  }
                }
              }
              if (islower(board[row_to][column_to_int]) > 0 && isupper(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='k')
              {
                for( int i = 0; i<2; i++)
                {
                  for(int j=0; j<8; j++) 
                  {
                    if(bijeli_jede[i][j] == ' ') 
                    {
                      bijeli_jede[i][j] = board[row_to][column_to_int];
                      board[row_to][column_to_int] = ' ';
                    }
                  }
                }
              }
            }
          else 
            moze=0;
        }
      }
    }
    else if(column_from_int - column_to_int < 0) //Desno
    {
      for(int i = column_from_int+1; i<=column_to_int; i++)
      {
        if(board[row_to][i] != ' ') 
        {
          if(i==column_to_int)
          {
            if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='K')
            {
              for( int i = 0; i<2; i++)
              {
                for(int j=0; j<8; j++) 
                {
                  if(crni_jede[i][j] == ' ') 
                  {
                    crni_jede[i][j] = board[row_to][column_to_int];
                    board[row_to][column_to_int] = ' ';
                  }
                }
              }
            }
            if (islower(board[row_to][column_to_int]) > 0 && isupper(board[row_from][column_from_int]) > 0 && board[row_to][column_to_int]!='k')
            {
              for( int i = 0; i<2; i++)
              {
                for(int j=0; j<8; j++) 
                {
                  if(bijeli_jede[i][j] == ' ') 
                  {
                    bijeli_jede[i][j] = board[row_to][column_to_int];
                    board[row_to][column_to_int] = ' ';
                  }
                }
              }
            }
          }
          else 
            moze=0;
        }
      }
    }    
  }
  else
  {
    moze=0;
    ilegalno=1;
  }
  if(moze == 1) 
  {
    if (isupper(board[row_to][column_to_int]) > 0 && islower(board[row_from][column_from_int]) > 0)
    {
      for( int i = 0; i<2; i++)
      {
        for(int j=0; j<8; j++) 
        {
          if(crni_jede[i][j] == ' ') 
          {
            crni_jede[i][j] = board[row_to][column_to_int];
            board[row_to][column_to_int] = ' ';
          }
        }
      }
    }
    logika_za_crtanje(row_to, row_from, column_to, column_from, board);
  }
  else
  {
    moze = 1;
    ilegalno = 1;
  }
  ilegalno=0;
}