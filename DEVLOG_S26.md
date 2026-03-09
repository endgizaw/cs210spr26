# Developer Log (DEVLOG.md)
## Monopoly Board Simulator (Spring 2026)

Minimum **6 entries** required

Each entry must document learning and reasoning. Fabricated bugs are not expected.

---

## Allowed Entry Types
Each entry may be one of the following:

1) **Bug Fix Entry**
- The issue encountered.
- Error messages or symptoms.
- Attempts made.
- Final resolution.

2) **Edge Case / Testing Entry**
- A failure discovered through testing.
- The specific input/state that caused it.
- The change you made to handle it correctly.

3) **Engineering Decision Entry (up to 2 allowed)**
- A design decision you made.
- An alternative approach you considered.
- Why you chose one approach over another (tradeoffs).

---

### Entry 1
**Date:** 2026-03-07  
**Entry Type:**  Engineering Decision  
**Task worked on: addSpace()**  
**Issue or decision: was incrementing before checking if list is empty**  
**Error message / symptom (if applicable):**  
**What I tried: had if condition as nodeCount == 0**  
**Fix / resolution (or final decision): changed it to !headNode and moved nodeCount++ after check**  
**Commit(s): **  

---

### Entry 2
**Date:** 2026-03-08  
**Entry Type:**  Engineering Decision  
**Task worked on: movePlayer() **  
**Issue or decision: playerNode was not actually moving / was not handling empty lists / logic for incrementing passGoCount was wrong**  
**Error message / symptom (if applicable):**  
**What I tried: was using playerNode->nextNode = playerNode / can not handle empty list / had it as if playerNode == tailNode for passGoCount++**  
**Fix / resolution (or final decision): removed that line from movePlayer() and now handles empty list and made it playerNode == headNode**  
**Commit(s): changed it to playerNode == headNode so that it increments after reaching the headNode not tailNode**  

---

### Entry 3
**Date:** 2026-03-08  
**Entry Type:**  Testing Entry
**Task worked on: addMany()**  
**Issue or decision: addMany() was not correctly adding nodes or keeping track of new nodes that were being made**  
**Error message / symptom (if applicable):**  
**What I tried: only had addMany as a while loop but was only adding nodes and not maintaining the circular loop**  
**Fix / resolution (or final decision): redid entire function to handle full list as well as maintaining the circular list**  
**Commit(s):**  

---

### Entry 4
**Date:** 2026-03-08  
**Entry Type:** Bug Fix   
**Task worked on: findByColor()**  
**Issue or decision: was not properly returning names of properties that had the same color**  
**Error message/symptom (if applicable): would only return color or nothing at all**  
**What I tried: at first I had set up my function noting the color of the property but not its name**  
**Fix / resolution (or final decision): made it able to handle empty list and changed current->data.propertyColor to current->data.propertyName**  
**Commit(s):**  

---

### Entry 5
**Date:** 2026-03-08  
**Entry Type:** Bug Fix   
**Task worked on: printFromPlayer() **  
**Issue or decision: was not printing following ndoes**  
**Error message / symptom (if applicable):**  
**What I tried: I had missunderstood the usage of the function and calculated how many spaces were left in the list from the playerNode**  
**Fix / resolution (or final decision): redid funcsiton so that it displays the nodes ahead of player depending on what input count is**  
**Commit(s):**  

---

### Entry 6
**Date:** YYYY-MM-DD  
**Entry Type:** Bug Fix / Edge Case / Engineering Decision  
**Task worked on:**  
**Issue or decision:**  
**Error message / symptom (if applicable):**  
**What I tried:**  
**Fix / resolution (or final decision):**  
**Commit(s):**  
