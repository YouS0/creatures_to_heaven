void getPosition(int c[2], char type) {
    // c means controllable
    // unc means uncontrollable or the thing we're looking for
    
    
    //--- make distance array
    int unc[2]; // should be outside
    int distance[20][20];
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            int dx = c[0] - i;
            if (dx < 0) dx *= -1;
            int dy = c[1] - j;
            if (dy < 0) dx *= -1;
            
            distance[i][j] = dx + dy;
            
            if (distance[i][j] < 0) distance[i][j] *= -1;
        }
    }
    
    //--- find the nearest
    int steps = -1;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (board[i][j] == 'H' && (steps == -1 || distance[i][j] < steps)) {
                unc[0] = i;
                unc[1] = j;
                steps = distance[i][j];
            }
        }
    }
}