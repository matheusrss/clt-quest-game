# **Projeto de Jogo: Estrutura de classes** 🛡️⚔️💼
### **Professor: Felipe Carvalho Pellison**
## **Alunos**
#### Luis Gustavo Sanchez Marioto 2211498 [GitHub](https://github.com/KuroshiD)
#### Raul Emanoel Naves de Oliveira 2225210 [Github](https://github.com/lini32)
#### Matheus Ricardo Souza da Silva 2224100 [Github](https://github.com/matheusrss)
## **📂 Organização Geral do Projeto**

O projeto é organizado em diferentes diretórios, facilitando o desenvolvimento modular e a organização do código. A estrutura é a seguinte:

```
src
├── includes/       // Headers (.hpp)
├── impl/           // Implementações (.cpp)
├── utils/          // Funções utilitárias
├── data/           // Arquivos CSV para carregar dados
└ main.cpp        // Arquivo principal do jogo
```

---

## **🎒 Classe `Backpack` (Mochila)**

A classe `Backpack` gerencia os itens que o herói coleta, permitindo armazenar, adicionar e remover itens em uma pilha (LIFO — Last In, First Out). Representa a mochila do herói e é crucial para gerenciar os itens adquiridos no mapa.

### **🔑 Atributos Privados:**
- `Struct Node` Estrutura criada para a bolsa
- `Node *top` — Representa o item no topo da pilha de itens.

### **⚙️ Métodos Públicos:**

#### **➕ void addItem(Item *newItem)**  
Adiciona um item ao topo da mochila.  
**Descrição:** Insere um novo item na pilha, atualizando o topo para apontar para este novo item.

#### **➖ Item* removeItem()**  
Remove o item do topo da mochila.  
**Descrição:** Retira o item mais recentemente adicionado, retornando-o. O topo da pilha é atualizado para apontar para o próximo item.

#### **📊 int getItemCount() const**  
Retorna o número total de itens na mochila.  
**Descrição:** Fornece o número de itens atualmente armazenados

#### **🔍 Item* GetLastItem() const**  
Obtem o item do topo da pilha sem removê-lo.  
**Descrição:** Permite verificar qual item está no topo sem alterar a pilha.

---

## **🎒 Classe `Belt` (Cinto)**

A classe `Cinto` gerencia os itens que o herói coleta, permitindo armazenar, adicionar e remover itens uma lista, ou seja qualquer posição disponivel

### **🔑 Atributos Privados:**
- `Struct Node` — Estrutura criada para a bolsa
- `Node *head` — Representa o inicio da lista.
- `double maxWeightPerSlot` — Capacidade maxima por slot
- `int slotCount` — Quantidade de slots

### **⚙️ Métodos Públicos:**

#### **➕ void addItemToSlot(Item *item, int sloot)**  
Adiciona um item no sloot indicado se disponivel.  
**Descrição:** Insere um novo na lista no slot indicado.

#### **➖ Item* removeItemFromSlot(int slot)**  
Remove o item do cinto no slot indicado.  
**Descrição:** Retira o item do slot indicado se existir

#### **📊 double getMaxWeightPerSlot() const;**  
Obtem o a capacidade maxima de cada slot do cinto

---

## **🧍‍♂️ Classe `Hero` (Herói)**

A classe `Hero` controla o personagem principal do jogo, incluindo seus atributos como saúde, nome e inventário. O herói interage com o mapa, coleta armas e poções, e combate inimigos.

### **🔑 Atributos Privados:**

- `std::string name` — Nome do herói.
- `double currentHealth;` — Representa a saúde atual do herói.
- `double maxHealth;` — Representa a saúde máxima do herói.
- `Backpack backpack` — Mochila que contém itens coletados pelo herói.
- `Belt belt` — Representa o cinto do herói. contém os itens coletados pelo herói.
- `int baseDamage` — Dano base que o herói pode infligir.
- `Weapon *equippedWeapon` — Arma que o herói está utilizando.

### **⚙️ Métodos Públicos:**

#### **🏹 void attack(Enemy *enemy)**  
Permite ao herói atacar um inimigo.  
**Descrição:** O dano total é calculado com base na arma equipada e no dano base. O inimigo recebe esse dano e a batalha prossegue.

#### **⚔️ void equipWeapon(Weapon *weapon)**  
Equipe uma nova arma.  
**Descrição:** Atualiza a arma equipada pelo herói, substituindo a arma anterior pela nova.

#### **💼 void addItemToBackpack(Item *item)**  
Adiciona um item à mochila do herói.  
**Descrição:** Coloca um item na mochila do herói, seja uma arma ou uma poção.

#### **💼 void addItemToBelt(Item *item, int slot)**  
Adiciona um item ao cinto do herói.  
**Descrição:** Coloca um item no cinto do herói, seja uma arma ou uma poção, no slot indicado.

#### **🩸 bool isAlive() const**  
Verifica se o herói ainda está vivo.  
**Descrição:** Retorna `true` se a saúde do herói for maior que 0, indicando que ele pode continuar lutando.

### **🔎 Item* getItemFromBackpack() const**
### **🔎 Item* getItemFromBelt(int slot)**

**Descrição:** Obtem o Item desejado de cada uma das estruturas disponiveis

### **🔄 Funções complementares**
#### também contém funções complementares para manusear a arma equipada, gerenciar o dano(tanto dano que leva do inimigo quanto o oposto)
---

## **👹 Classe `Enemy` (Inimigo)**

A classe `Enemy` define os inimigos encontrados pelo herói no jogo. Cada inimigo tem atributos de saúde e ataque, e é controlado pela classe `Map`.

### **🔑 Atributos Privados:**

- `std::string enemyType` — Tipo de inimigo (ex: Goblin, Troll, Dragão).
- `int health` — Vida atual do inimigo.
- `int attackPower` — O poder de ataque do inimigo, utilizado em combates contra o herói.

### **⚙️ Métodos Públicos:**

#### **⚔️ void attack(Character *target)**  
Ataca um alvo, infligindo dano, o alvo geralmente é o heroi.  
**Descrição:** O inimigo inflige dano ao herói com base no seu poder de ataque. A saúde do herói é reduzida.

#### **🩸 bool isAlive() const**  
Verifica se o inimigo ainda está vivo.  
**Descrição:** Retorna `true` se a saúde do inimigo for maior que 0, permitindo que ele continue atacando.

#### **💀 void takeDamage(int damage)**  
Reduz a vida do inimigo com base no dano recebido.  
**Descrição:** O inimigo perde vida com base no valor de dano passado como argumento. Se a vida chegar a 0, o inimigo morre.

---

## **⚔️ Classe `Weapon` (Arma)**

A classe `Weapon` representa uma arma no jogo que o herói pode encontrar e utilizar. Cada arma tem um poder de ataque e uma descrição.

### **🔑 Atributos Privados:**

- `std::string name` — Nome da arma (ex: Espada Lendária).
- `std::string description` — Descrição da arma, explicando suas características únicas.
- `int attackPower` — Poder de ataque que a arma concede ao herói.
- `double weight` — peso da arma.
- `std::string suffix` sufixo da arma.
- `string prefix` — prefixo da arma.

### **⚙️ Métodos Públicos:**

#### **⚔️ int getAttackPower() const**  
Retorna o poder de ataque da arma.  
**Descrição:** Esse valor é adicionado ao ataque base do herói para calcular o dano total infligido aos inimigos.

#### **📝 std::string getDescription() const**  
Retorna a descrição completa da arma.  
**Descrição:** Usado para exibir as informações da arma quando o herói a encontra no jogo.

#### **🏷️ std::string getName() const**  
Retorna o nome da arma.  
**Descrição:** Fornece o nome da arma, exibido no jogo quando o herói a coleta ou a utiliza em combate.

---

## **🧪 Classe `Potion` (Poção)**

A classe `Potion` define poções que podem ser encontradas e usadas pelo herói para curar ou obter buffs temporários.

### **🔑 Atributos Privados:**

- `std::string name` — Nome da poção (ex: Poção de Cura).
- `std::string description` — Descrição da poção.
- `int healingPower` — Quantidade de saúde que a poção recupera.
- `double weight` — peso da poção.
- `std::string suffix` sufixo da poção.
- `string prefix` — prefixo da poção.

### **⚙️ Métodos Públicos:**

#### **💊 int getHealingPower() const**  
Retorna o poder de cura da poção.  
**Descrição:** Quando o herói utiliza a poção, esse valor é adicionado à sua vida atual.

#### **📝 std::string getDescription() const**  
Retorna a descrição completa da poção.  
**Descrição:** Usado para exibir as informações da poção quando o herói a encontra no jogo.

#### **🏷️ std::string getName() const**  
Retorna o nome da poção.  
**Descrição:** Fornece o nome da poção, mostrado ao herói ao encontrá-la ou utilizá-la.

---

## **🗺️ Classe `Map` (Mapa)**

A classe `Map` é uma classe template que define as diferentes salas que o herói pode encontrar no jogo. Dependendo do tipo de sala (inimigos, itens, ou vazias), diferentes interações ocorrem.

### **🔑 Atributos Privados:**

- `Hero *hero` — Referência ao herói atual, permitindo interação com o mapa.

### **⚙️ Métodos Públicos (Template):**

#### **🔄 void trigger(void *obj)**  
Dispara o evento correspondente ao tipo de sala.  
**Descrição:** Executa a interação quando o herói encontra um inimigo ou item. No caso de uma sala vazia, o herói descansa.

#### **🗺️ void displayMap(void *obj) const**  
Exibe a descrição da sala e o que foi encontrado nela.  
**Descrição:** Mostra os detalhes da sala, como inimigos ou itens, ou, no caso de uma sala vazia, uma mensagem informando que o herói descansou.

#### **👥 template <typename T> class Map**  
**Especializações para `Enemy`, `Weapon`, `Potion`, e `void`**  
**Descrição:** Cada especialização lida com diferentes tipos de interações: combate com inimigos, coleta de armas, uso de poções ou descanso em salas vazias.

---

## **🎮 Classe `Game` (Jogo)**

A classe `Game` gerencia o fluxo principal do jogo, controlando o herói, inimigos, mapas, e o progresso através dos níveis.

### **

🔑 Atributos Privados:**

- `Hero *hero` — O herói controlado pelo jogador.
- `int level` — Nível atual do jogo.
- `int score` — Pontuação do jogador.
- `MapInterface *currentMap` — Referência para o mapa atual em que o herói está.
- `Enemy* enemies` — Lista de inimigos disponíveis no jogo.
- `Weapon* weapons` — Lista de armas disponíveis.
- `Vector* potions` — Lista de poções.

### **⚙️ Métodos Públicos:**

#### **🗺️ void changeMap(MapInterface *newMap)**  
Muda o mapa atual para o novo mapa fornecido.  
**Descrição:** O herói avança para uma nova sala, seja enfrentando inimigos, encontrando itens ou descansando.

#### **🎮 void start()**  
Inicia o loop principal do jogo.  
**Descrição:** Controla o fluxo do jogo, gerando mapas aleatórios, combatendo inimigos e coletando itens até o herói morrer.

#### **🛠️ void increaseScore(double enemyAttack, double health)**  
Aumenta a pontuação do jogador.  
**Descrição:** O score é atualizado com base nos atributos dos inimigos derrotados.

#### **🏁 void end()**  
Encerra o jogo, salvando a pontuação do jogador.  
**Descrição:** O nome e a pontuação final do jogador são salvos e exibidos.

---
