#  SmartSwine: Especificação Técnica do Projeto
### Documento de Arquitetura e Requisitos do Sistema



---

##  Sumário
1. [Visão Geral e Arquitetura](#1-visão-geral-e-arquitetura)
2. [Usuários do Sistema](#2-usuários-do-sistema)
3. [Funcionalidades Detalhadas](#3-funcionalidades-detalhadas)
4. [Requisitos Funcionais (RF) e Não Funcionais (RNF)](#4-requisitos-funcionais-rf-e-não-funcionais-rnf)
5. [Stack Tecnológica (Hardware e Software)](#5-stack-tecnológica-hardware-e-software)
6. [Regras de Negócio e Condições Críticas](#6-regras-de-negócio-e-condições-críticas)

---

## 1. Visão Geral e Arquitetura

O **SmartSwine** opera sob o paradigma de **Edge Computing combinado com Cloud IoT**. Os nós sensores instalados nas baias coletam dados brutos do ambiente e do lote, realizam um pré-processamento local via microcontroladores e transmitem os dados estruturados via protocolo leve (`MQTT`) para um servidor de nuvem ou broker local. Uma camada analítica baseada em regras limiarizadas e modelos de aprendizado leve processa os dados para detecção de anomalias térmicas e comportamentais.

---

## 2. Usuários do Sistema

* **Estudante / Operador Técnico:** Responsável pela montagem física, inspeção de rotina dos sensores e recebimento dos alertas primários na granja-escola.
* **Pesquisador / Professor:** Acessa o painel analítico para extração de logs históricos, correlação de variáveis climáticas com o desempenho do lote e validação de hipóteses científicas.
* **Administrador do Sistema:** Responsável pelo gerenciamento de credenciais de acesso, calibração de sensores e manutenção da infraestrutura de rede e software.

---

## 3. Funcionalidades Detalhadas

* **F1 - Monitoramento Ambiental em Tempo Real:** Coleta contínua (intervalos configuráveis de 60 segundos) de temperatura do ar, umidade relativa e concentração de gases nocivos ($\text{NH}_3$).
* **F2 - Análise Acústica e Comportamental (Módulo Avançado):** Captura de áudio ambiente para varredura espectral em busca de padrões vocais de estresse ou tosse aguda através de limiares de frequência sonora.
* **F3 - Motor de Alertas Preditivos:** Sistema de disparo automatizado de notificações via protocolo HTTP/Webhooks (integração com Telegram Bot ou painel web) quando parâmetros ambientais violam as zonas de conforto térmico.
* **F4 - Dashboard de Visualização Analítica:** Interface web responsiva para plotagem de gráficos de séries temporais (temperatura vs. tempo, umidade vs. tempo) e status de conectividade dos nós IoT.

---

## 4. Requisitos Funcionais (RF) e Não Funcionais (RNF)

### Requisitos Funcionais (RF)
* **RF01:** O sistema deve registrar os dados coletados pelos sensores no banco de dados a cada ciclo de amostragem configurado.
* **RF02:** O sistema deve disparar um alerta visual e sonoro/mensagem em até **15 segundos** caso a temperatura ultrapasse o limite crítico pré-estabelecido.
* **RF03:** O sistema deve permitir o cadastro, edição e exclusão lógica de novos nós sensores vinculados a baias específicas.
* **RF04:** O sistema deve exportar relatórios em formato `.CSV` contendo o histórico de telemetria das últimas 24 horas.

### Requisitos Não Funcionais (RNF)
* **RNF01 (Confiabilidade):** O firmware do nó sensor deve possuir rotina de *Watchdog Timer* para reinicialização automática em caso de travamento por falha de rede.
* **RNF02 (Desempenho):** O broker MQTT deve suportar conexões concorrentes de múltiplos nós sensores sem perda de pacotes (Packet Loss < 1%).
* **RNF03 (Segurança):** A comunicação entre os nós IoT e o broker de dados deve utilizar criptografia de transporte (`TLS/SSL` ou autenticação por token de dispositivo).
* **RNF04 (Usabilidade):** O dashboard web deve ser responsivo, adaptando-se a telas de smartphones e desktops utilizados pelos operadores na granja.

---

## 5. Stack Tecnológica (Hardware e Software)

### Hardware Necessário
* **Microcontrolador Principal:** ESP32 (com suporte nativo a Wi-Fi e Bluetooth BLE para conectividade IoT).
* **Sensores Ambientais:**
  * Sensor digital de temperatura e umidade relativa (ex: **DHT22** ou **SHT31** de alta precisão).
  * Sensor de gás eletroquímico ou semicondutor para detecção de amônia (ex: **MQ-135** ou equivalente calibrado).
* **Módulo Acústico (Opcional/Fase 2):** Módulo de microfone analógico/digital com amplificador (ex: **MAX9814**).
* **Atuadores (Simulação de Automação):** Relés de estado sólido (SSR) para acionamento de lâmpadas de aquecimento ou exaustores em bancada de teste.

### Software Necessário
* **Firmware / Embarcado:** C++ utilizando o ecossistema **Arduino IDE** ou **PlatformIO**.
* **Protocolo de Mensageria:** Broker MQTT (ex: *Mosquitto* local ou servidor gerenciado na nuvem).
* **Backend e Banco de Dados:** Node.js com Express para API intermediária e banco de dados NoSQL (ex: *MongoDB*) ou série temporal (*InfluxDB*) para armazenamento de telemetria.
* **Frontend / Dashboard:** Node-RED (para prototipagem rápida de painéis IoT) ou React.js.

---

## 6. Regras de Negócio e Condições Críticas

* **RN01 (Faixas de Conforto Térmico por Fase):** O sistema deve aplicar matrizes de regras dinâmicas. Exemplo: Para leitões em fase de creche, a faixa de temperatura ideal situa-se estritamente entre **26°C e 32°C**. Temperaturas abaixo de 24°C ativam imediatamente a bandeira de "Risco de Hipotermia/Amontoamento".
* **RN02 (Limiar de Toxicidade de Gases):** Concentrações de amônia ($\text{NH}_3$) superiores a **20 ppm** por mais de 15 minutos consecutivos geram uma ordem de prioridade alta no painel de alertas, exigindo intervenção de ventilação forçada.
* **RN03 (Integridade de Conexão):** Caso um nó sensor pare de enviar batimentos cardíacos (*heartbeat*) por mais de 5 minutos, o servidor deve registrar uma ocorrência de falha de hardware/rede no painel administrativo.
