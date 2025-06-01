# egzaminoUzduotis

## Programos aprašymas 

Programa skirta apdoroti failą: išrinkti skirtingus žodžius, jų pasikartojimų skaičių, vietą bei apdoroti nuorodas.

## Naudojimosi instrukcijos, reikalavimai 

Išankstiniai reikalavimai:
- VS _compiler_
- CMake

Naudojimosi instrukcija:
- _clone_ repozitoriją arba parsisiųsti repozitorijos ZIP failą
- nunaviguokite į repozitoriją _(C:\Users\username\Downloads\egzaminoUzduotis)_
- Programos komoiliavimas: rm build -Recurse -Force ; cmake -B build -S . ; cmake --build build
- Programos paleidimas: .\build\Debug\MyProject.exe

### Reikalingi files
- input folder
    - `article.txt` - tekstas, kurį apdorojame 
    - `tlds-alpha-by-domain.txt` - galimi _domains_ (failas būtinas korektiškam programos veikimui)

- output folder
    - `URL.txt` - tekste rastos nuorodos
    - `wordsTimes.txt` - failas, kuriame matoma kiek kartų pasikartojo tekste esantys skirtingi žodžiai
    - `crossReference.txt` - failas, kuriame matoma kuriose vietose (eilutėse) pasikartojo tekste esantys skirtingi žodžiai