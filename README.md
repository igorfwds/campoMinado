# Campo Minado

<pre>
 ::::::::      :::     ::::    ::::  :::::::::   ::::::::   ::::    ::::  ::::::::::: ::::    :::     :::     :::::::::   ::::::::  
:+:    :+:   :+: :+:   +:+:+: :+:+:+ :+:    :+: :+:    :+:  +:+:+: :+:+:+     :+:     :+:+:   :+:   :+: :+:   :+:    :+: :+:    :+: 
+:+         +:+   +:+  +:+ +:+:+ +:+ +:+    +:+ +:+    +:+  +:+ +:+:+ +:+     +:+     :+:+:+  +:+  +:+   +:+  +:+    +:+ +:+    +:+ 
+#+        +#++:++#++: +#+  +:+  +#+ +#++:++#+  +#+    +:+  +#+  +:+  +#+     +#+     +#+ +:+ +#+ +#++:++#++: +#+    +:+ +#+    +:+ 
+#+        +#+     +#+ +#+       +#+ +#+        +#+    +#+  +#+       +#+     +#+     +#+  +#+#+# +#+     +#+ +#+    +#+ +#+    +#+ 
#+#    #+# #+#     #+# #+#       #+# #+#        #+#    #+#  #+#       #+#     #+#     #+#   #+#+# #+#     #+# #+#    #+# #+#    #+# 
 ########  ###     ### ###       ### ###         ########   ###       ### ########### ###    #### ###     ### #########   ########  
</pre>


## Descrição
O Campo Minado é um jogo clássico de lógica que desafia os jogadores a explorar um campo de quadrados. Cada quadrado desse campo revela um número que indica a quantidade de minas adjacentes. O objetivo é desvendar todas as células do campo, evitando as minas escondidas.

## Linguagem de Programação e Biblioteca
O jogo foi desenvolvido em linguagem C e utiliza a biblioteca ncurses para proporcionar uma interface gráfica interativa.

Este jogo foi desenvolvido como parte do aprendizado na disciplina de programação imperativa e funcional. Um projeto prático para consolidar conceitos teóricos e aplicar habilidades de programação em um contexto do mundo real.

## Instruções de Compilação
### Pré-requisitos do Sistema
O jogo é compatível com sistemas operacionais Linux, MacOS e Windows com WSL (Windows Subsystem for Linux).
Para o Windows, ao abrir o terminal, digite ‘bash’ para habilitar a compatibilidade com o Linux. Dessa maneira, estará fazendo funcionar o WSL.

### Instalando Biblioteca ncurses
- **Linux e Windows com WSL:**
  ```bash
  sudo apt-get install libncurses5-dev libncursesw5-dev
  ```
- **MacOS:**
  - Instale o Homebrew (se não estiver instalado):
    ```bash
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```
  - Instale a biblioteca ncurses:
    ```bash
    brew install ncurses
    ```

### Instruções de Compilação
- **Linux e Windows com WSL:**
  ```bash
  make
  ./campo_minado
  ```
- **MacOS:**
  ```bash
  gcc -o campo_minado campo_minado.c main.c -lncurses
  ./campo_minado
  ```

O jogo estará pronto para ser jogado após a execução bem-sucedida.

## Instruções de Uso
### Menu Inicial
Ao iniciar o jogo, um menu é apresentado com as opções:
1. Novo Jogo
2. Instruções
3. Sair

### Iniciar Novo Jogo
Selecionar "Novo Jogo" inicia uma partida com um campo 10x10 e 10 bombas distribuídas aleatoriamente.

### Controles no Campo Minado
- a: Movimenta para a esquerda.
- w: Movimenta para cima.
- s: Movimenta para baixo.
- d: Movimenta para a direita.
- Espaço: Abre uma célula do campo minado.

### Revelação das Células
Ao abrir uma célula, é exibido o número de bombas nas 8 células vizinhas.

### Objetivo do Jogo
Abra todas as células sem bombas para vencer. Vitória ou derrota são seguidas pela revelação das posições das bombas.


### Pontuação
- Cada célula aberta sem bomba adiciona 1 ponto à pontuação final.
- A pontuação final é a soma de todas as células abertas antes de encontrar uma bomba.

### Após o Jogo
Independentemente do resultado, o jogador é redirecionado ao menu inicial, onde pode escolher entre as opções disponíveis.

### Sair
A opção de sair pode ser feita durante a execução do jogo (tecla "q") ou no menu inicial (opção "3").
