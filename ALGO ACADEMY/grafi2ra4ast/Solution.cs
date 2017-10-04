using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    public static bool DijkstraAlgorithm(Dictionary<Node, List<Connection>> graph, Node source, Node end, long safety, int maxTime)
    {
        var queue = new PriorityQueue<Node>();

        foreach (var node in graph)
        {
            node.Key.DijkstraDistance = long.MaxValue;
        }

        source.DijkstraDistance = 0;
        queue.Enqueue(source);

        while (queue.Count != 0)
        {
            var currentNode = queue.Dequeue();

            if (currentNode.DijkstraDistance == long.MaxValue)
            {
                break;
            }

            foreach (var neighbor in graph[currentNode])
            {
                var currentTime = currentNode.DijkstraDistance;
                currentTime += currentNode.Id == 1 ? 1 : safety;

                var waitTime = WaitTime(currentTime, neighbor);
                var potDistance = currentTime + waitTime + neighbor.TravellingTime;
                if (potDistance < neighbor.Node.DijkstraDistance)
                {
                    neighbor.Node.DijkstraDistance = potDistance;
                    queue.Enqueue(neighbor.Node);
                }
            }
        }

        return end.DijkstraDistance <= maxTime;
    }

    public static long WaitTime(long currentTime, Connection flight)
    {
        long departureTime = flight.DepartureTime;
        if (currentTime <= departureTime)
        {
            return departureTime - currentTime;
        }
        else
        {
            currentTime %= flight.Period;
            departureTime %= flight.Period;
            if (currentTime <= departureTime)
            {
                return departureTime - currentTime;
            }
            else
            {
                return departureTime + flight.Period - currentTime;
            }
        }
    }

    public class Node : IComparable
    {
        public Node(int id)
        {
            this.Id = id;
        }

        public int Id { get; private set; }

        public long DijkstraDistance { get; set; }

        public int CompareTo(object obj)
        {
            if (!(obj is Node))
            {
                return -1;
            }

            return this.DijkstraDistance.CompareTo((obj as Node).DijkstraDistance);
        }
    }

    public class Connection
    {
        public Connection(Node node, long travellingTime, long departure, long period)
        {
            this.Node = node;
            this.TravellingTime = travellingTime;
            this.DepartureTime = departure;
            this.Period = period;
        }

        public Node Node { get; set; }

        public long TravellingTime { get; set; }

        public long DepartureTime { get; set; }

        public long Period { get; set; }
    }

    public class PriorityQueue<T> where T : IComparable
    {
        private T[] heap;
        private int index;

        public PriorityQueue()
        {
            this.heap = new T[16];
            this.index = 1;
        }

        public int Count
        {
            get
            {
                return this.index - 1;
            }
        }

        public void Enqueue(T element)
        {
            if (this.index >= this.heap.Length)
            {
                this.IncreaseArray();
            }

            this.heap[this.index] = element;

            int childIndex = this.index;
            int parentIndex = childIndex / 2;
            this.index++;

            while (parentIndex >= 1 && this.heap[childIndex].CompareTo(this.heap[parentIndex]) < 0)
            {
                T swapValue = this.heap[parentIndex];
                this.heap[parentIndex] = this.heap[childIndex];
                this.heap[childIndex] = swapValue;

                childIndex = parentIndex;
                parentIndex = childIndex / 2;
            }
        }

        public T Dequeue()
        {
            T result = this.heap[1];

            this.heap[1] = this.heap[this.Count];
            this.index--;

            int rootIndex = 1;

            while (true)
            {
                int leftChildIndex = rootIndex * 2;
                int rightChildIndex = (rootIndex * 2) + 1;

                if (leftChildIndex > this.index)
                {
                    break;
                }

                int minChild;
                if (rightChildIndex > this.index)
                {
                    minChild = leftChildIndex;
                }
                else
                {
                    if (this.heap[leftChildIndex].CompareTo(this.heap[rightChildIndex]) < 0)
                    {
                        minChild = leftChildIndex;
                    }
                    else
                    {
                        minChild = rightChildIndex;
                    }
                }

                if (this.heap[minChild].CompareTo(this.heap[rootIndex]) < 0)
                {
                    T swapValue = this.heap[rootIndex];
                    this.heap[rootIndex] = this.heap[minChild];
                    this.heap[minChild] = swapValue;

                    rootIndex = minChild;
                }
                else
                {
                    break;
                }
            }

            return result;
        }

        public T Peek()
        {
            return this.heap[1];
        }

        private void IncreaseArray()
        {
            var copiedHeap = new T[this.heap.Length * 2];

            for (int i = 0; i < this.heap.Length; i++)
            {
                copiedHeap[i] = this.heap[i];
            }

            this.heap = copiedHeap;
        }
    }


    static void Main(string[] args)
    {
        int cityToTravel = int.Parse(Console.ReadLine());
        int numberOfFlights = int.Parse(Console.ReadLine());

        var graph = new Dictionary<Node, List<Connection>>();
        var used = new Dictionary<int, Node>();

        for (int i = 0; i < numberOfFlights; i++)
        {
            var parts = Console.ReadLine().Split(new[] { ',' }, StringSplitOptions.RemoveEmptyEntries);
            var startCity = int.Parse(parts[0]);
            var endCity = int.Parse(parts[1]);
            var departureTime = int.Parse(parts[2]);
            var travellingTime = int.Parse(parts[3]);
            var period = int.Parse(parts[4]);

            // start city
            Node startCityNode;
            if (used.ContainsKey(startCity))
            {
                startCityNode = used[startCity];
            }
            else
            {
                startCityNode = new Node(startCity);
                used.Add(startCity, startCityNode);
                graph.Add(startCityNode, new List<Connection>());
            }

            // end city
            Node endCityNode;
            if (used.ContainsKey(endCity))
            {
                endCityNode = used[endCity];
            }
            else
            {
                endCityNode = new Node(endCity);
                used.Add(endCity, endCityNode);
                graph.Add(endCityNode, new List<Connection>());
            }

            var connection = new Connection(endCityNode, travellingTime, departureTime, period);
            graph[startCityNode].Add(connection);
        }
        
        int time = int.Parse(Console.ReadLine());

        long min = 1;
        long max = 1000000000;
        long current = 1;
        while(min + 1 < max)
        {
            current = max - ((max - min) / 2);
            if (DijkstraAlgorithm(graph, used[1], used[cityToTravel], current, time))
            {
                min = current;
            }
            else
            {
                max = current;
            }
        }

        Console.WriteLine(min);
    }
}
