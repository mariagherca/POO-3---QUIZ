# Proiect: Aplicație Quiz Educațional

## Descriere

Această aplicație console C++ oferă un sistem de testare educațională pentru studenți, prin quiz-uri tematice (Geografie, Istorie, Biologie), urmărind scorul și progresul individual. Proiectul aplică concepte avansate de OOP, cum ar fi principiile SOLID, programarea generică (șabloane), și design patterns.

## Structura Funcțională

- Afișarea și rezolvarea quiz-urilor din fișiere text.
- Evaluarea scorului pe baza răspunsurilor.
- Afișarea progresului salvat pentru fiecare student.
- Lecții afișabile cu sau fără decoratori (ex: cu timp limită).
- Folosirea de template-uri pentru generalizarea lecțiilor.

## Cerințe implementate

### ✅ Programare Generică (Templates)

- **Clasă șablon:** `Lectie<T>` este o clasă șablon care poate reprezenta o lecție generică cu orice tip de conținut (`Quiz`, `std::vector<std::string>`, etc).
- **Funcție membră dependentă de T:** `afiseazaContinut()` are comportament diferit în funcție de T (prin specializare pentru `std::vector<std::string>`).
- **Funcție șablon liberă:** `afiseazaLectie()` este o funcție template care primește orice tip de `Lectie<T>` și apelează metoda corespunzătoare de afișare.

### ✅ Design Patterns implementate

1. **Strategy Pattern**
   - Clasa `EvaluareStrategy` definește o interfață de evaluare.
   - `EvaluarePunctaj` este o implementare concretă care calculează scorul ca sumă de puncte.

2. **Observer Pattern**
   - Clasa `Observer` definește o interfață generală.
   - `Student` primește notificări (metoda `update()`) privind progresul obținut după quiz.

3. **Decorator Pattern**
   - `ILectie` este o interfață de lecție.
   - `LectieText` este o lecție de bază, decorată de `LectieCuTimer` care adaugă o limită de timp afișată.

## Structura Fișierelor

```
.
├── Intrebare.h / Intrebare.cpp        # Structură întrebări quiz
├── Quiz.h / Quiz.cpp                  # Management quiz: încărcare, rulare
├── Evaluare.h / Evaluare.cpp          # Evaluare prin strategy pattern
├── Observer.h / Observer.cpp          # Student observator (observer pattern)
├── Lectie.h                           # Clasă șablon Lectie<T>
├── Decorator.h / Decorator.cpp        # Decoratori pentru lecții (decorator pattern)
├── Progres.h / Progres.cpp            # Persistența progresului într-un fișier
├── main.cpp                           # Meniul aplicației și logica principală
├── quiz_geografie.txt                 # Exemplar quiz tematic
├── progres.txt                        # Fișier pentru salvarea progresului
└── README.md                          # Documentația proiectului
```

## Cum se rulează

1. Compilează toate fișierele `.cpp` într-un singur binar:
```bash
g++ *.cpp -o quizApp
```

2. Rulează aplicația:
```bash
./quizApp
```

3. Urmează instrucțiunile din meniu.

## Extensibilitate

- Se pot adăuga noi tipuri de quiz sau lecții fără a modifica codul existent.
- Suportul pentru șabloane permite utilizarea `Lectie<T>` cu orice tip nou de conținut.
- Design patterns-urile folosite permit o scalare elegantă a funcționalității.

## Autori

- Proiect realizat pentru tema 3 la POO, anul universitar 2024–2025.
