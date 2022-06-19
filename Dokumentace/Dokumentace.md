# MAP - SumoRobot
# Obsah
- Obsah
- Minisumo
- Vývojový diagram
- Blokové schéma
- Schéma zapojení
- Tabulka použitých součástek
- Informace o součáskách
- Fotodokumentace
- Videoukázka
- Závěr


# Minisumo
V ringu soutěží vždy jen dvojice robotů, kteří se položí za startovací čáry. Po startu se snaží vytlačit jeden druhého mimo ring. Pokud se jeden z robotů dotkne jakoukoli svou částí plochy mimo ring, prohrává.To platí i v případě, když z robota odpadne jakákoliv jeho část a ta následně bude vytlačena nebo sama se dotkne plochy mimo ring.  

# Vývojvý diagram

# Blokové schéma
```mermaid
flowchart TD;
    Napájení --> STM-8;
    Napájení --> H-můstek;
    STM-8 -- PWM--> H-můstek;
    H-můstek --> DC-motory;
    IR_senzory <--> STM-8;
    Ultrazvukový_senzor <--> STM-8

```

# Schéma zapojení
<img src="./img/schema.jpg" width=30% height=30%>

# Tabulka použitých součástek
V této tabulce nalezneme seznam použitých součástek.
|      Název       |   Typ   | počet| cena za kus |                                           datasheet (webová stránka)                                               |
|      :---        | :----:         |:----: |     ---:    |                                           :----:                                                            |
|STM8              |NUCLEO-8S208RB  | 1x   |366 Kč|[STM8S208RB](https://www.st.com/resource/en/user_manual/um2364-stm8s208rbt6-nucleo64-board-stmicroelectronics.pdf)   |
|IR Senzor         |TCRT5000 |2x    |        18 Kč|[Reflective Optical Sensor with Transistor Output](https://www.laskakit.cz/user/related_files/tcrt5000_datasheet.pdf)|
|Ulzvuk. senzor    |HC-SR04  |1x    |        38 Kč|[HC-SR04 User Guide](https://www.laskakit.cz/user/related_files/hc-sr04_ultrasonic_module_user_guidejohn.pdf)        |
|Dc. motor         |GA12-N20 |2x    |       108 Kč|[G12-N20 Geared Mini DC Motor](https://www.handsontec.com/dataspecs/GA12-N20.pdf)                                    |
|H-můstek          |L298N    |1x    |        58 Kč|[DUAL FULL-BRIDGE DRIVER](https://www.laskakit.cz/user/related_files/l298n.pdf)                                      |
|Držák baterii     |BH-341-1A|1x    |        34 Kč|[COMF BH-341-1A](https://www.laskakit.cz/comf-bh-341-1a-drzak-baterie-4xaa-dratove-vyvody/)                          |
|Kola              |-        |2x    |        28 Kč|[Kolo gumové 43x19mm](https://www.laskakit.cz/kolo-gumene-43x19mm/)                                                  |
|Stavebnice Merkur |-        |-     |          -  |[MerkurToys.cz](https://eshop.merkurtoys.cz/k4-stavebnice)                                                           |
|Stahovací pásky   |-        |-     |        90 Kč|[100-pack, Stahovací páska (2.5x200)](https://www.alza.cz/100-pack-stahovaci-paska-2-5x200-d1488352.htm)             |
|Propojovací kabely|F/M, M/M, F/F|-|80 Kč|[Propojovacíkabely M/f](https://www.laskakit.cz/dupont-propojovaci-kabely-40ks-m-f-samec-samice--10cm-/?gclid=EAIaIQobChMIxPqH14Cv-AIVw4ODBx2sxAdBEAQYAyABEgIR2_D_BwE)|
# Informace o součástkách

## STM-8
STM8 Nucleo-64 je vývojová deska s STM8S208RB MCU. MikroKontroler je mozek celého robota. Napájení zdílí spoleně s H-můstkem.  
<img src="./img/STM8.webp" width=50% height=50%>

## Infračervený senzor
Robot disponuje 2 infračervenými senzory pro sledování čáry. Senzory kontrolují, zda se robot nachází v hracím poli a že z něj nevyjede.  
<img src="./img/IR.webp" width=30% height=30%>

## Ultrazvukový senzor
V přední časti robota se nachází ultrazvukový senzor, jehož prací je určit přítomnost nepřítele. Nachází-li se nepřítel před robotem, robot se rozjede a plnou parou do protívníka narazí avytlačí ho ven z hřiště.  
<img src="./img/UZ.jpg" width=30% height=30%>

## DC Motor
Stejnosměrné motory s převodovkou jsou jedinným pohonem sumorobota. Nenechte se ale s nimi zmást, i přes jejich velikost dokáží předat dostatečně velkou sílu, aby poháněli robota a zároveň protivníka vytlačili ven z hřoště.  
<img src="./img/DC-motor.jpg" width=30% height=30%>

## H-můstek
Jedná se o ovládací prvek, který ovládá chod stejnosměrných motorů. Umožňuje motorům chod dopředu, dozadu ale i každý jiným směrem. H-můstek je napájen 4x 1.5V bateriemi.  
<img src="./img/l298.jpg" width=30% height=30%>

## Držák baterií
Nápájení obstarávají 4 AA baterie, které jsou usazeny do držáku baterii COMF BH-341-1A.  
<img src="./img/bat.jpg" width=30% height=30%>
## Kola
Dc motory jsou osazeny koly s gumovou pneumatikou o rozměrech 43x19mm. Kola byla navržena přímo pro hřídel motoru.  
<img src="./img/kolo.jpg" width=30% height=30%>

## Stavebnice Merkur
Tělo robota je kompletně sestaveno ze stavebnice Merkur, se kterou si určitě každý znas alespoň jednou hrál.  
<img src="./img/merkur.jpg" width=30% height=30%>

## Ostatní součástky
Dalšími použitými součástkami jsou propojovací kebeli, které slouží k propojení jednotlivách částí robota a stahovací pásky, které momáhají držet určité součástky na místě.  
<img src="./img/paska.jpg" width=30% height=30%> <img src="./img/kabel.jpg" width=30% height=30%>

# Fotodokumentace

<img src="./img/bot_dole.jpg" width=50% height=50%><img src="./img/bot_bok.jpg" width=50% height=50%>
<img src="./img/bot_predek.jpg" width=50% height=50%><img src="./img/bot_zadek.jpg" width=50% height=50%>
<img src="./img/bot_vrch.jpg" width=50% height=50%>

# Videoukázka


# Závěr
Při tvorbě projetku jsme si prošli jak pozitivními, tak i negativními zkušenostmi. Nadosmrti si budeme pomatovat první pohyby našeho vytvoru, ze kterého se postupem času stal funkční sumorobot. Bohužel jseme se neobešli bez problémů. Hned ze začátku programovací fáze se objevil proplém, kde jsme nebyli schopni vyřešit funkci ultrazvukového senzoru. Po několika dnech zkoušení se ukázalo že problém není na naši straně a my byli nuceni senzor vymněnit, což nás o několik dní zdrželo. Každopádně jsme se naučili mnohé jak o součástkách se kterými by jsem se ve škole nesetkali, tak i programovacím jazyce C. Doufejme, že náš robot vyjde z arény jako výtěz.
# Rozdělení Práce
## Petr Cupal
- Návrh zapojení
- Zajištění součástek
- Zapojení robota
- Sestavení
- Dokumentace(Schéma zapojení, bokové chchéma, Seznam součástek, )

## Matin Bernát
- Návrh programu
- Zapojení robota
- Tvorba programu
- dokumentace (Návrh vývojového diagramu)