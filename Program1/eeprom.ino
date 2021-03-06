

void eepromBegin() {

  /*kP = (float)EEPROM.read(eP) / 10;
    kI = (float)EEPROM.read(eI) / 10;
    kD = (float)EEPROM.read(eD) / 10;

    baseSpeed = (int)EEPROM.read(eBase);
    maxSpeed = (int)EEPROM.read(eMax);
    //debug =  (int)EEPROM.read(eDebug);*/

}

void saveEEPROM() {

  int addr = 9;
  EEPROM.update(addr, isMazeSolved);
  addr += 1;

  // saving the maze
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      EEPROM.update(addr, maze[i][j]);
      EEPROM.update(addr + 50, mazeWalls[i][j]);
      addr += 1;
    }
  }
  EEPROM.update(120, finalXPosition);
  EEPROM.update(121, finalYPosition);
  EEPROM.update(123, posX);
  EEPROM.update(124, posY);
  
}

void updateMazeAddress(int i, int j) {
  EEPROM.update(10 + ((i * 6) + j), maze[i][j]);
}

void updateMazeWallAddress(int i, int j) {
  EEPROM.update(50 + ((i * 6) + j), mazeWalls[i][j]);
}
void loadEEPROM() {

  int addr = 9;
  isMazeSolved = EEPROM.read(addr);
  addr += 1;
  if (1) {
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        maze[i][j] = EEPROM.read(addr);
        mazeWalls[i][j] = EEPROM.read(50 + addr);

        if (maze[i][j] == 255) maze[i][j] = 0;
        if (mazeWalls[i][j] == 255) maze[i][j] = -1;

        addr += 1;
      }
    }
  }

  finalXPosition = EEPROM.read(120);
  finalYPosition = EEPROM.read(121);
  boxXPosition = EEPROM.read(122);
  boxYPosition = EEPROM.read(123);
}

void saveCommandQueueFromEEPROM() {
  short int arr[] = {0,3,1,0,3,3,0,10,3,1,0,0,1,3,4};
  for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
    EEPROM.update(80 + i, arr[i]);
  }
}
void loadCommandQueueFromEEPROM() {
  for (int i = 0; i < 36; i++) {
    solvedCommandQueue[i] = EEPROM.read(80 + i);
  }
}
void cleanEEPROM() {

  int addr = 9;
  EEPROM.update(addr, 0);
  addr += 1;
  if (1) {
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        EEPROM.update(addr, 255);
        EEPROM.update(addr + 50, 255);
        EEPROM.update(80 + addr, 0);
        addr += 1;
      }
    }
  }

  EEPROM.update(120, 0);
  EEPROM.update(121, 0);
  EEPROM.update(122, 0);
  EEPROM.update(123, 0);
}

