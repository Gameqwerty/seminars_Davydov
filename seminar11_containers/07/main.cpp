#include <iostream>
#include <vector>
#include <queue>
#include "image.hpp"

struct Point
{
    int x;
    int y;
};

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " input.ppm output.ppm\n";
        return 1;
    }

    Image img(argv[1]);

    const int w = img.getWidth();
    const int h = img.getHeight();

    Image::Color black{0, 0, 0};
    Image::Color green{0, 255, 0};
    Image::Color red{255, 0, 0};
    Image::Color blue{0, 0, 255};

    Point start{-1, -1};
    Point finish{-1, -1};

    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            Image::Color c = img.getPixel(x, y);
            if (c == green)
                start = {x, y};
            else if (c == red)
                finish = {x, y};
        }
    }

    if (start.x < 0 || finish.x < 0)
    {
        std::cerr << "No start or finish pixel found\n";
        return 1;
    }

    std::vector<std::vector<int>> dist(h, std::vector<int>(w, -1));
    std::vector<std::vector<Point>> prev(h, std::vector<Point>(w, {-1, -1}));

    std::queue<Point> q;
    q.push(start);
    dist[start.y][start.x] = 0;

    const int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    const int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

    auto passable = [&](int x, int y) -> bool
    {
        Image::Color c = img.getPixel(x, y);
        return !(c == black);
    };

    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();

        if (cur.x == finish.x && cur.y == finish.y)
            break;

        for (int dir = 0; dir < 8; ++dir)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                continue;
            if (dist[ny][nx] != -1)
                continue;
            if (!passable(nx, ny))
                continue;

            dist[ny][nx] = dist[cur.y][cur.x] + 1;
            prev[ny][nx] = cur;
            q.push({nx, ny});
        }
    }

    if (dist[finish.y][finish.x] == -1)
    {
        std::cerr << "Path not found\n";
        return 1;
    }

    Point cur = finish;
    while (!(cur.x == start.x && cur.y == start.y))
    {
        if (!(cur.x == finish.x && cur.y == finish.y))
            img.setPixel(cur.x, cur.y, blue);

        cur = prev[cur.y][cur.x];
    }

    img.savePPMBinary(argv[2]);

    return 0;
}
