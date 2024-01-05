#include <bits/stdc++.h>
/* Dado un mapeo de palabra : lista de múltiples palabras, y un párrafo p,
reemplazar en p las indicencias de cualquier cadena (puede ser una palabra
o varias) con la key correspondiente.
EJEMPLO #1:
>>
map = {
    "cat" : ["Lion", "tiger", "leopard"],
    "Ocean" : ["Shark", "Whale"],
    "Bird" : ["parrots", "owls", "sparrow"]
}

paragraph = "Lion kills leopard ___ whale _ _ _ bad Shark _ _ _ beautiful parrots"

<<
"cat kills cat ___ whale _ _ _ bad Ocean _ _ _ beautiful Bird"

EJEMPLO #2:
>>
map = {
    "Cat": ["Lion the king", "Tiger the competitor", "Innocent Leopard"],
    "Ocean" : ["dangerous shark", "large whale"]
}
paragraph = "_ _ _ _ _ Lion the king, killed Inocent Leopard _ _ _ _ _ large
whale plays with shark _ _ _"
<<
"_ _ _ _ _ Cat, killed Cat _ _ _ _ _ Ocean plays with shark _ _ _"
*/

/* IDEA DE SOLUCIÓN
Usar una estructura de datos Trie modificada, es decir, podrá almacenar
mayúsculas, minúsculas y espacios. Además guardará la key del map cuando sea
'end of sentence', así de podrá saber hasta donde buscar.

Se construye el trie una sola vez, entonces se va procesando el parráfo:
    Se va leyendo usando dos punteros, a y b, cada vez que avance b se mueve la
    búsqueda en el trie:
        + si se encuentra un mismatch, entonces avanzar b hasta la siguiente
            palabra, a=b y b++, y reiniciar la búsqueda en el trie.
        + si p[b] = caracter_raro, entonces, b avanza hasta encontrar de nuevo
            una letra [A-Z | a-z], y entonces a=b y b++.
        + si se llega al end of sentence, entonces se guarda a y b, y la key,
            luego, a = b+1, b++
*/

using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl;

int main() {
	return 0;
}
