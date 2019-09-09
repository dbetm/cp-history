// Un programa en Java para calcular todas los pares de rutas más cortas
import java.util.*;
import java.lang.*;
import java.io.*;
// Time Complexity: O(V^3)
class AllPairShortestPath {

    final static int INF = 9999, V = 4;

    void floydWarshall(int graph[][]) {
        // Se declara la matriz solución
        int dist[][] = new int[V][V];
        /* Se inicializa la solución con los mismos valores de entrada,
        o podemos decir que sin considerar ningún vértice intermedio, ya
        tenemos las rutas más cortas para cada par.
        */
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = graph[i][j];
            }
        }

        // Se agregan todos los vértices uno a uno al conjunto de
        // vértices intermedios.
        /*
        --> Antes de comenzar la iteración, tenemos ya las distancias más
        cortas entre todos los pares de vértices tal que las distancias más
        cortas consideran solo los vértices del conjunto {1,2,3,...,k-1} como
        vértices intermedios.
        --> Después del término de una iteración, el k-vértice es agregado al
        conjunto de vértices intermedios, entonces: {1,2,3,...,k}
        */
        for (int k = 0; k < V; k++) {
            // Seleccionar todos los vértices como origen, uno por uno
            for (int i = 0; i < V; i++) {
                /* Seleccionar todos los vértices destino por cada
                vértice origen actual */
                for (int j = 0; j < V; j++) {
                    /* Si el vértice k es más la ruta más corta de i a j,
                    entonces se actualiza el valor de dist[i][j].
                    */
                    if(dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        printSolution(dist);
    }

    void printSolution(int dist[][]) {
        System.out.println("La siguiente matriz muestra las distancias " +
            "más cortas entre cada par de vértices."
        );
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if(dist[i][j] == INF) System.out.print("INF ");
                else System.out.print(dist[i][j] + "  ");
            }
            System.out.println("");
        }
    }

    public static void main(String[] args) {
        // Grafo de entrada, ejemplo
        /*
               10
        (0)------->(3)
         |         /|\
        5|          |
         |          | 1
        \|/         |
        (1)------->(2)
              3
        */
        int grafo[][] = {
            {0, 5, INF, 10},
            {INF, 0, 3, INF},
            {INF, INF, 0, 1},
            {INF, INF, INF, 0},
        };

        AllPairShortestPath a = new AllPairShortestPath();
        // Mostramos la solución
        a.floydWarshall(grafo);
    }
}
