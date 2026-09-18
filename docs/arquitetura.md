## FLUXOGRAMA DE FUNCIONAMENTO 
Cartão Trello Correspondente:https://trello.com/c/nIT9g2uE/6-teste-do-m%C3%B3dulo-rel%C3%A9-com-o-sistema-de-nebuliza%C3%A7%C3%A3o
---
```mermaid
flowchart TD
    A([Inicio / Loop ESP32]) --> B[Leitura dos Sensores:\nDHT22, MQ-135 e Boia]
    
    B --> C{Temperatura > 28°C\nOU Umidade < 50%?}
    
    C -- SIM --> D[1. Liga Nebulização/Ventilador\n2. Envia Alerta no Telegram]
    C -- NÃO --> E[Desliga Relés de Climatização]
    
    D --> F{Nível do Bebedouro BAIXO\nOU Amônia > Limite Crítico?}
    E --> F
    
    F -- SIM --> G[Envia Alerta Urgente de Manejo\npara o Técnico Marcos]
    F -- NÃO --> H[Manter Operação Normal]
    
    G --> I[Aguarda 30 segundos]
    H --> I
    
    I --> A
