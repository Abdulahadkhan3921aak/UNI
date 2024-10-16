import tensorflow as tf


class Agent:

    def __init__(self, state_dim, action_dim):
        # Define the policy network
        self.policy_network = tf.keras.Sequential([
            tf.keras.layers.Dense(64, activation='relu',
                                  input_shape=(state_dim,)),
            tf.keras.layers.Dense(action_dim, activation='softmax')
        ])

        # Define the value network
        self.value_network = tf.keras.Sequential([
            tf.keras.layers.Dense(64, activation='relu',
                                  input_shape=(state_dim,)),
            tf.keras.layers.Dense(1)
        ])

    def get_action(self, state):
        # Get the probability distribution over actions from the policy network
        action_probs = self.policy_network.predict(state)

        # Sample an action based on the probability distribution
        action = tf.random.categorical(action_probs, 1)[0][0]
        return action

    def get_value(self, state):
        # Get the estimated value of the current state from the value network
        value = self.value_network.predict(state)
        return value[0][0]
