class Symptom:
        def __init__(self, name):
                self.name = name
                self.present = False

class Condition:
    def __init__(self, name, symptoms):
        self.name = name
        self.symptoms = symptoms

def get_yes_or_no_input(prompt):
    while True:
        response = input(prompt + " (yes/no): ").strip().lower()
        if response in ["yes", "no"]:
            return response == "yes"
        else:
            print("Please enter 'yes' or 'no'.")
            
def diagnose(symptoms, conditions):
        possible_conditions = []
        for condition in conditions:
                if all(getattr(symptoms[symptom.name], 'present') for symptom in condition.symptoms):
                        possible_conditions.append(condition.name)
        return possible_conditions


def main():
    # Define Symptoms
    symptom_fever = Symptom("Fever")
    symptom_cough = Symptom("Cough")
    symptom_headache = Symptom("Headache")
    symptom_sore_throat = Symptom("Sore Throat")
    symptom_memory_loss = Symptom("Memory Loss")
    symptom_confusion = Symptom("Confusion")
    symptom_mood_swings = Symptom("Mood Swings")
    symptom_weakness = Symptom("Weakness")
    symptom_joint_pain = Symptom("Joint Pain")
    
    # Define Conditions
    condition_flu = Condition("Flu", [symptom_fever, symptom_cough, symptom_headache])
    condition_common_cold = Condition("Common Cold", [symptom_cough, symptom_sore_throat])
    condition_migraine = Condition("Migraine", [symptom_headache])
    condition_alzheimers = Condition("Alzheimer's", [symptom_memory_loss, symptom_confusion, symptom_mood_swings])
    condition_arthritis = Condition("Arthritis", [symptom_joint_pain, symptom_weakness])
    condition_common_flu = Condition("Common Flu", [symptom_fever, symptom_cough, symptom_weakness])

    symptoms = {
        "Fever": symptom_fever,
        "Cough": symptom_cough,
        "Headache": symptom_headache,
        "Sore Throat": symptom_sore_throat,
        "Memory Loss": symptom_memory_loss,
        "Confusion": symptom_confusion,
        "Mood Swings": symptom_mood_swings,
        "Weakness": symptom_weakness,
        "Joint Pain": symptom_joint_pain
    }

    conditions = [condition_flu, condition_common_cold, condition_migraine, condition_alzheimers, condition_arthritis, condition_common_flu]

    # Ask about symptoms
    for symptom in symptoms.values():
        symptom.present = get_yes_or_no_input(f"Please answer in yes or no\n Do you have {symptom.name.lower()}?")

    # Diagnose
    possible_conditions = diagnose(symptoms, conditions)

    if possible_conditions:
        print("Possible condition:")
        for condition in possible_conditions:
            print("-", condition)
    else:
        print("No matching conditions found.")

if __name__ == "__main__":
    main()
    
"""Please answer in yes or no
 Do you have fever? (yes/no): yes
Please answer in yes or no
 Do you have cough? (yes/no): no
Please answer in yes or no
 Do you have headache? (yes/no): yes
Please answer in yes or no
 Do you have sore throat? (yes/no): no
Please answer in yes or no
 Do you have memory loss? (yes/no): yes
Please answer in yes or no
 Do you have confusion? (yes/no): yes
Please answer in yes or no
 Do you have mood swings? (yes/no): yes
Please answer in yes or no
 Do you have weakness? (yes/no): no
Please answer in yes or no
 Do you have joint pain? (yes/no): no
Possible conditions you might be suffering from may be :
- Migraine
- Alzheimer's"""
