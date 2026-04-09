class Robot {
public:
    vector<string> dirs = {"North", "East", "South", "West"};
    vector<pair<int, int>> steps = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int d;
    int x, y;
    int w, h,cycle;
    Robot(int width, int height) {
        d = 1;
        x = 0;
        y = 0;
        w = width;
        h = height;
        cycle = 2*(width + height)-4; 
    }

    void step(int num) {
        num %= cycle;
        if(num == 0)num = cycle;
        while (num--) {
            int nx = steps[d].first + x, ny = steps[d].second + y;
            if (nx == w || ny == h || nx == -1 || ny == -1) {
                d = (d + 3) % 4;
                num++;
            } else {
                x = nx;
                y = ny;
            }
        }
    }

    vector<int> getPos() { return {x, y}; }

    string getDir() { return dirs[d]; }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */