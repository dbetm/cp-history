/* OUTLINE
1. Se modela el problema como un bosque enraizado de
árboles disjuntos (no tienen elementos en común entre sí).
2. Estrategia divide y vencerás (ahorrando cómputo con DP).
3. Cada componente conectado del bosque se puede resolver de
forma independiente.
    3.1. Se pueden probar iniciando cada triggerer, esto va eliminar
    un path desde ese trigger hasta la raíz, dejando muchos árboles
    pequeños, que se pueden resolver de forma recursiva.
    3.2 El número de subárboles es igual al número de nodos en el árbol, k.
*/
