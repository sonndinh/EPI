/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
private:
    // Visited coordinates, encoded as string.
    unordered_set<string> visited;
    
    string coor_to_str(int x, int y) {
        return (to_string(x) + "," + to_string(y));
    }
    
public:
    void dfs_visit(Robot& robot, int x, int y) {
        // Clean this cell.
        robot.clean();
        visited.insert(coor_to_str(x, y));
        
        // Turn left.
        string left_coor = coor_to_str(x, y-1);
        robot.turnLeft();
        if (visited.find(left_coor) == visited.end() && robot.move()) {
            robot.turnRight();
            dfs_visit(robot, x, y-1);
            robot.turnRight();
            robot.move();
            robot.turnLeft();
        } else {
            robot.turnRight();
        }
        
        // Turn right.
        string right_coor = coor_to_str(x, y+1);
        robot.turnRight();
        if (visited.find(right_coor) == visited.end() && robot.move()) {
            robot.turnLeft();
            dfs_visit(robot, x, y+1);
            robot.turnLeft();
            robot.move();
            robot.turnRight();
        } else {
            robot.turnLeft();
        }
        
        // Move up.
        string up_coor = coor_to_str(x-1, y);
        if (visited.find(up_coor) == visited.end() && robot.move()) {
            dfs_visit(robot, x-1, y);
            robot.turnLeft();
            robot.turnLeft();
            robot.move();
            robot.turnRight();
            robot.turnRight();
        }
        
        // Move down.
        string down_coor = coor_to_str(x+1, y);
        robot.turnLeft(); robot.turnLeft();
        if (visited.find(down_coor) == visited.end() && robot.move()) {
            robot.turnRight(); robot.turnRight();
            dfs_visit(robot, x+1, y);
            robot.move();
        } else {
            robot.turnRight(); robot.turnRight();
        }
    }
    
    void cleanRoom(Robot& robot) {
        return dfs_visit(robot, 0, 0);
    }
};
