import hashlib
import struct
import time

def create_genesis_block(merkle_root, timestamp, nonce, bits, version, reward):
    # Block version
    version_bytes = struct.pack("<I", version)
    
    # Hash of the previous block (genesis block has no previous block)
    prev_block_hash = bytes.fromhex("00" * 32)
    
    # Merkle root
    merkle_root_bytes = bytes.fromhex(merkle_root)
    
    # Timestamp (UNIX format)
    timestamp_bytes = struct.pack("<I", timestamp)
    
    # Bits (difficulty)
    bits_bytes = struct.pack("<I", bits)
    
    # Nonce (starting at 0)
    nonce_bytes = struct.pack("<I", nonce)
    
    # Construct the block header
    header = version_bytes + prev_block_hash[::-1] + merkle_root_bytes[::-1] + timestamp_bytes + bits_bytes + nonce_bytes
    
    # Hash the block header twice with SHA-256
    hash_result = hashlib.sha256(hashlib.sha256(header).digest()).digest()
    return hash_result[::-1].hex()  # Reverse the byte order for display

# Initial parameters for the genesis block
genesis_merkle_root = "4a5e1e4baab89f3a32518a88b8a3025d11a3a987b12b8b9dbdd7d3a6d6e98fdd"  # Example Merkle root
genesis_timestamp = int(time.mktime(time.strptime("01 Jan 2024 00:00:00 UTC", "%d %b %Y %H:%M:%S UTC")))
genesis_bits = 0x1d00ffff  # Difficulty bits (Bitcoin's initial difficulty)
genesis_version = 1
genesis_reward = 50 * 100000000  # Initial reward in satoshis (50 coins)
genesis_nonce = 0

# Difficulty target as a large number
target = (1 << (256 - 0x1d)) * 0x00ffff

# Mine the genesis block by finding the correct nonce
while True:
    hash_hex = create_genesis_block(genesis_merkle_root, genesis_timestamp, genesis_nonce, genesis_bits, genesis_version, genesis_reward)
    
    # Convert the hash to a number and compare with the target
    if int(hash_hex, 16) < target:
        print(f"Genesis Block Mined!\nHash: {hash_hex}\nNonce: {genesis_nonce}")
        break
    
    # Increment the nonce and try again
    genesis_nonce += 1
