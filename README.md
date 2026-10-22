vas_fu7_random csomag
Ez a csomag a ROS 2 beadandóhoz készült. Egy C++ Publisher node-ot tartalmaz, amely egy folyamatosan frissülő hőmérsékletszenzort szimulál.

Node-Topic diagram
Kódrészlet
```mermaid
graph LR
    A[vas_fu7_node] -- "std_msgs/String" --> B((sensor_temperature))
