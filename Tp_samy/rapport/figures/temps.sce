clf();
n = [5, 10, 1000, 2000, 3000, 5000]; // Nombre de noeuds
temps = [0.002, 0.002, 3.46, 38.11, 133.78, 618.27]; // Temps des benchmarks

coeff = 0.5e-8; // Coefficient de proportionnalité

t = linspace(0, 5500);
plot(benchmark, temps, 'r*');
plot(t, coeff*t^3);
xtitle("Temps d''exécution des benchmarks", "Nombre de noeuds de l''arbre", "Temps (en secondes)");
