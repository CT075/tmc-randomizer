﻿namespace ColorzCore.DataTypes
{
	internal class CaseInsensitiveString
	{
		private string data;

		public CaseInsensitiveString(string input)
		{
			String = input;
		}

		public string String
		{
			get => data;
			set => data = value.ToUpper();
		}

		public override int GetHashCode()
		{
			return String.GetHashCode();
		}

		public override bool Equals(object obj)
		{
			return String == obj.ToString();
		}

		public override string ToString()
		{
			return String;
		}
	}
}
