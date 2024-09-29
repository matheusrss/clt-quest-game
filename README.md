```markdown
# Projeto RPG em C++

Este projeto é um jogo RPG desenvolvido em C++. O projeto segue uma estrutura de arquivos específica e pode ser compilado e executado usando um `Makefile`.

## Estrutura do Projeto

```
-bin
  └── exe
-doc
  └── docfiles
-src
  ├── includes
  │   └── (todos os arquivos .hpp)
  └── impl
      └── (todas as implementacões de .cpp)
-main.cpp
```

## Classes e Métodos

### Item
- **Descricão**: Classe base para itens no jogo.
- **Métodos**:
  - `virtual ~Item() = 0;` - Destrutor virtual puro.
  - `virtual void initialize(string name, double weight) = 0;` - Inicializa o item com nome e peso.
  - `virtual string getName() const = 0;` - Obtém o nome do item.
  - `virtual double getWeight() const = 0;` - Obtém o peso do item.

### Potion (Derivada de Item)
- **Descricão**: Representa pocões que podem curar o herói.
- **Métodos**:
  - `Potion(string name, double weight, double healingPower);` - Construtor que define nome, peso e poder de cura.
  - `void initialize(string name, double weight) override;` - Inicializa o item.
  - `string getName() const override;` - Obtém o nome da pocão.
  - `double getWeight() const override;` - Obtém o peso da pocão.
  - `double getHealingPower() const;` - Obtém o poder de cura da pocão.
  - `~Potion() override;` - Destrutor.

### Weapon (Derivada de Item)
- **Descricão**: Representa armas que o herói pode usar.
- **Métodos**:
  - `Weapon(string name, double weight, double attackPower);` - Construtor que define nome, peso e poder de ataque.
  - `void initialize(string name, double weight) override;` - Inicializa o item.
  - `string getName() const override;` - Obtém o nome da arma.
  - `double getWeight() const override;` - Obtém o peso da arma.
  - `double getAttackPower() const;` - Obtém o poder de ataque da arma.
  - `~Weapon() override;` - Destrutor.

### Character
- **Descricão**: Classe base para todos os personagens (herói e inimigos).
- **Métodos**:
  - `Character(string name, double maxHealth);` - Construtor que define nome e saúde maxima.
  - `virtual void attack(Character* target) = 0;` - Método de ataque (implementado pelas subclasses).
  - `virtual string getDescription() const = 0;` - Obtém a descricão do personagem (implementado pelas subclasses).
  - `string getName() const;` - Obtém o nome do personagem.
  - `double getMaxHealth() const;` - Obtém a saúde maxima.
  - `double getCurrentHealth() const;` - Obtém a saúde atual.
  - `void takeDamage(double damage);` - Reduz a saúde atual com base no dano recebido.
  - `void heal(double amount);` - Aumenta a saúde atual com base na cura.
  - `virtual ~Character() = 0;` - Destrutor virtual puro.

### Enemy (Derivada de Character)
- **Descricão**: Representa inimigos no jogo.
- **Métodos**:
  - `Enemy(string name, double maxHealth, double attackPower, string description);` - Construtor que define nome, saúde maxima, poder de ataque e descricão.
  - `void attack(Character* target) override;` - Ataca o herói.
  - `string getDescription() const override;` - Obtém a descricão do inimigo.
  - `double getAttackPower() const;` - Obtém o poder de ataque do inimigo.
  - `~Enemy() override;` - Destrutor.

### Hero (Derivada de Character)
- **Descricão**: Representa o herói controlado pelo jogador.
- **Métodos**:
  - `Hero(string name, double maxHealth, double maxWeightPerSlot);` - Construtor que define nome, saúde maxima e peso maximo por slot.
  - `void attack(Character* target) override;` - Ataca um inimigo.
  - `string getDescription() const override;` - Obtém a descricão do herói.
  - `void addItemToBackpack(Item* item);` - Adiciona um item na mochila.
  - `void addItemToBelt(Item* item, int slot);` - Adiciona um item no cinto.
  - `Item* getItemFromBackpack() const;` - Obtém o item do topo da mochila.
  - `Item* getItemFromBelt(int slot) const;` - Obtém o item de um slot específico do cinto.
  - `~Hero() override;` - Destrutor.

### Backpack
- **Descricão**: Representa a mochila do herói.
- **Métodos**:
  - `Backpack();` - Construtor que inicializa a mochila.
  - `bool addItem(Item* item);` - Adiciona um item na mochila.
  - `Item* removeItem();` - Remove o item do topo da mochila.
  - `Item* getLastItem() const;` - Obtém o item do topo da mochila.
  - `int getItemCount() const;` - Obtém a quantidade de itens na mochila.
  - `~Backpack();` - Destrutor.

### Belt
- **Descricão**: Representa o cinto do herói.
- **Métodos**:
  - `Belt(double maxWeightPerSlot);` - Construtor que define o peso maximo por slot.
  - `bool addItemToSlot(Item* item, int slot);` - Adiciona um item a um slot específico.
  - `Item* removeItemFromSlot(int slot);` - Remove um item de um slot específico.
  - `Item* getItemFromSlot(int slot) const;` - Obtém o item de um slot específico.
  - `double getMaxWeightPerSlot() const;` - Obtém o peso maximo por slot.
  - `~Belt();` - Destrutor.

## Implementacão das Classes

As implementacões das classes devem ser feitas em arquivos `.cpp` dentro do diretório `src/impl`. Cada classe deve ter um arquivo `.cpp` correspondente ao seu cabecalho `.hpp`.

## Observacões

- Certifique-se de que o diretório `src/includes` contém todos os arquivos `.hpp` necessarios.
- Certifique-se de que o diretório `src/impl` contém as implementacões dos arquivos `.cpp`.


```

## Compilacão e Execucão

Para compilar o projeto, utilize o `Makefile` incluído no repositório. Basta executar o comando `make build` na raiz do projeto. O `Makefile` ira compilar todos os arquivos e gerar o executavel na pasta `bin`.
### Comando para Compilar

```bash
make build
```

